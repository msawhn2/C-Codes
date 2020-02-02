void straightwire(){
	 
	 const int n = 1000;
	const int N = 10;
	const float pi = 3.14159265;
	int i, j, k, l;
	float L = 1;
	float By[N][N];
	float x[N];
	float z[N];

	float C = (1.26*pow(10,-6))/(4*pi);
	float dx = (2.*L)/(N-1);
	 // float dx = 0.05;
	 float y,rx,ry,rz,r,xw,yw,zw;
	 // float By[N][N],x[n];
	 float dl = 2*L/(n-1);
	 float dlx,dly,dlz;
	  // int i,j;

y=0;
	 dlx = dl;
	 dly = 0;
	 dlz = 0;

c = new TCanvas("c", "B of an infinite wire", 0,0,1000,350);
c->Draw();
hist2 = new TH2D("hist2","Magnetic field of an infinite wire",N,-L,L+0.001,N,1,N+0.001);

for (int i=0; i<N;i++){
	 x[i] = -1.0*L + dx*i;


	 	for(int j=0;j<N;j++){

	 		
	 		z[j] = 1.0 + j;
	 		By[i][j] = 0;


	 	for(int w=0;w<n-1;w++){

	 		xw = -1.0*L + dl/2.0 + w*dl;
	 		yw = 0;
	 		zw = 0;


	 		dlx = dl;
	 		dly = 0;
	 		dlz = 0;

	 		rx = x[i] - xw;
	 		ry = y -  yw;
	 		rz = z[j] - zw;
	 		r = sqrt(rx*rx + ry*ry + rz*rz);

	 		By[i][j] = By[i][j] + C* ((dlz*rx - dlx*rz)/(r*r*r));


	 	}	

	 	}
}
	 
  hist2->GetXaxis()->SetTitle("x [m]");
  hist2->GetYaxis()->SetTitle("y [m]");
  hist2->GetZaxis()->SetTitle("z [m]");
  gStyle->SetOptStat(0);

  		for(int i=0; i<N ; i++){

  			for( int j=0; j<N ;j++){
  				hist2->Fill(x[i], z[j], -1.0*By[i][j]);
  			}
  		}
  	

  		hist2->Draw("surf2");



}