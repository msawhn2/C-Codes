void randomwalks(){
	

	
     const int Nx = 20;
     int n =1000;		
	// const int Nt = 300;		
	float D = 1.0;			
	float P[Nx], Pnew[Nx];	
	float dt = 0.5;			
	float dx = 1.;
	float Nt = 3000;//300;//10*dt;
	float r;

	float nu = (D*dt)/(dx*dx);	

	hplot = new TH2D("hplot", "Random walk",Nx,0,D,Nt,0,(dt*Nt));
	cnvs = new TCanvas("cnvs", "Random walk",0,0,900,600);
	TH1D *h1 = new TH1D("h1","h1",Nx,0,D);
	

	for(int i = 0; i < Nx; i++)	{
    	 P[i] = Pnew[i]=0;		
	}

	P[Nx/2] = Pnew[Nx/2]=n;
        
	for(int j = 0; j < 10; j++)	{

		for(int i = 1; i < Nx-1; i++)	{
            
			r = gRandom->Rndm()*P[i];
			//cout<<r<<endl;
			Pnew[i+1] += r;
			Pnew[i-1] += P[i]-r;

			//cout<<P[i]<<endl;
			//hplot->SetBinContent(i+1, j+1, Pnew[i]);
		}
		for(int i = 1; i < Nx-1; i++)	{
            
			P[i] = Pnew[i];
			
		}

	}

		
	for(int i = 1; i < Nx-1; i++)	{
        			
		h1->SetBinContent(i,P[i]);
	}	
    h1->Draw();

/*
	hplot->GetXaxis()->SetTitle("x");
	hplot->GetYaxis()->SetTitle("y");
	hplot->GetZaxis()->SetTitle("z");
	gStyle->SetOptStat(0);
	hplot->Draw("COLZ");

	return;
	cnvs1 = new TCanvas("cnvs1","Random walk",0,0,700,700);
	h2 = new TH2D ("h2","Random walk",Nx,0,D,Nt,0,(dt*Nt));

	for(int i = 0; i < Nx; i++)	{
		if(i==Nx/2)	
			{P[i] = 1.0;
			Pnew[i] = 1.0;
		}

		else
			{P[i] = 0.;
			Pnew[i] = 0.;}	
		// else	{T[i] = 100.0;}
	}
	
	for(int j = 0; j < Nt; j++)	{
		for(int i = 1; i < Nx-1; i++)	{
			Pnew[i] = P[i] + nu*(P[i+1]+P[i-1]-2*P[i]);
			P[i] = Pnew[i];
			//cout<<P[i]<<endl;
			h2->SetBinContent(i+1, j+1, P[i]);
		}
	}
	
	h2->GetXaxis()->SetTitle("x");
	h2->GetYaxis()->SetTitle("y");
	h2->GetZaxis()->SetTitle("z");
	gStyle->SetOptStat(0);
	h2->Draw("surf2");

	cnvs2 = new TCanvas("cnvs2","Random walk",0,0,700,700);
	TH1D *h1 = new TH1D("h1","h1",100,-1.,1.);
	
	for(int i = 0; i < Nx; i++)	{
		if(i==Nx/2)	
			{P[i] = 1.0;
			Pnew[i] = 1.0;
		}

		else
			{P[i] = 0.;
			Pnew[i] = 0.;}	
		// else	{T[i] = 100.0;}
	}
	
	for(int j = 0; j < Nt; j++)	{
		for(int i = 1; i < Nx-1; i++)	{
			Pnew[i] = P[i] + nu*(P[i+1]+P[i-1]-2*P[i]);
			P[i] = Pnew[i];
			//cout<<P[i]<<endl;
			h1->SetBinContent(i+1, j+1, P[i]);
		}
	}
	
	h1->GetXaxis()->SetTitle("x [m]");
	h1->GetYaxis()->SetTitle("t [s]");
	// gStyle->SetOptStat(0);
	h1->Draw();


*/


}