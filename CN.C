void CN(){
	
	const int Nx = 20;		
	const int N = 300;		
	float K = 237.0;		
	float C = 900.0;		
	float rho = 2700.0;		
	float L = 1.0;			
	float T[N][N], Tnew[N][N];	
	float dt = 2.0;			
	 float dx = L /20;		
	float eta = (K*dt)/(C*rho*dx*dx);	
	float a[N],d[N],c[N],b[N],h[N],p[N],x[N],A[N][N];

	// for(int i =0; i < N-1; i++){
	// A[i][i] = (2/eta)+2;
	// A[i][i] = A[i+1][i] = -1.;
	// }
	// A[N-1][N-1] = (2/eta)+2;
	hplot = new TH2D("hplot", "Heat Diffusion of an Al Rod",Nx,0,L,N,0,(dt*N));
	cnvs = new TCanvas("cnvs", "Heat Diffusion of an Al Rod",0,0,900,600);
	

	for(int i=0; i<N; i++){
	
		T[i][0] = 100.;
		T[0][i] = 0.;
		T[N-1][i] = 0.;
		T[0][i+1] = 0.;
		T[N-1][i+1] = 0.;

	}

	for(int i=0;i<N;i++){
		d[i] = ((2./eta)+2.);
	}
	for(int i=0;i<N-1;i++){
		c[i] = -1.0;
	}

	for(int i=1;i<N;i++){
		a[i] = -1.0;
	}

	for(int i=0;i<N-2;i++){

		b[i] = T[i][0] + ((2./eta)-2.) *T[i+1][0] + T[i+2][0];
	}

		h[0] = c[0]/d[0];
		p[0] = b[0]/d[0];
	
	for(int i=1;i<N;i++){

		h[i] = c[i]/(d[i]-a[i]*h[i-1]);
		p[i] = (b[i]-a[i]*p[i-1])/(d[i]-a[i]*h[i-1]); 
	}

	x[N-1] = p[N-1];
	
	for(int i=N-2;i>0;i--){
		x[i] = p[i]-h[i]*x[i-1];
		
	}
	for(int i = 0; i < N; i++){
		for{int j = 0; j < N; j++}{
			hplot->SetBinContent(i + 1, j + 1, T[i][j]);
		}
	}
	hplot->GetXaxis()->SetTitle("x [m]");
	hplot->GetYaxis()->SetTitle("t [s]");
	hplot->GetZaxis()->SetTitle("T [degrees celsius]");
	gStyle->SetOptStat(0);
	hplot->Draw("surf2");

}