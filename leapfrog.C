void leapfrog(){
	

      	const int Nx = 20;		
	const int Nt = 300;		
	float K = 237.0;		
	float C = 900.0;		
	float rho = 2700.0;		
	float L = 1.0;			
	float T[Nx], Tnew[Nx];	
	float dt = 2.0;			
	float dx = L / Nx;		
	float eta = (K*dt)/(C*rho*dx*dx);	

	hplot = new TH2D("hplot", "Heat Diffusion of an Al Rod",Nx,0,L,Nt,0,(dt*Nt));
	cnvs = new TCanvas("cnvs", "Heat Diffusion of an Al Rod",0,0,900,600);
	
	for(int i = 0; i < Nx; i++)	{
		if(i==0)	
			{T[i] = 0.0;
			Tnew[i] = 0.0;
		}

		else if(i==(Nx-1))
			{T[i] = 0;
			Tnew[i] = 0;}	
		else	{T[i] = 100.0;}
	}
	
	for(int j = 0; j < Nt; j++)	{
		for(int i = 1; i < Nx-1; i++)	{
			Tnew[i] = T[i] + eta*(T[i+1]+T[i-1]-2*T[i]);
			T[i] = Tnew[i];
			cout<<T[i]<<endl;;
			hplot->SetBinContent(i+1, j+1, T[i]);
		}
	}
	
	hplot->GetXaxis()->SetTitle("x [m]");
	hplot->GetYaxis()->SetTitle("t [s]");
	hplot->GetZaxis()->SetTitle("T [degrees celsius]");
	gStyle->SetOptStat(0);
	hplot->Draw("surf2");
}

