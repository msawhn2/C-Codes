void boxmueller(){
	
	const int nmax = 100000;
	float dx = 0.01;
	float c = 300;
	float dt = 0.00003;
	float r2;
	float y[nmax];
	float x[nmax];
	const int time = 100;
	float pi = 3.1415;
	float z1[nmax],z2[nmax];

	
	TH1D *h1 = new TH1D("h1","h1",100,-3.,3.);
	TH1D *h2 = new TH1D("h2","h2",100,-3.,3.);
	h1->Sumw2();
	h2->Sumw2();
	h1->SetMinimum(0);
	h2->SetMinimum(0);



	for(int i=0; i<nmax-1;i++){

		x[i] =  gRandom->Rndm();
		y[i] =  gRandom->Rndm();
		 // exp(-1000*(x[i] - 0.3)*(x[i] - 0.3));
		z1[i] = sqrt(-2.0*log(x[i]))*cos(2*pi*y[i]);
		z2[i] = sqrt(-2.0*log(x[i]))*sin(2*pi*y[i]);
		// cout<<y[i]<<endl;
  //       cout<<sin(2*pi*y[i])<<endl;
		// cout<<z1[i]<<" "<<z2[i]<<endl;

		h1->Fill(z1[i]);
		h2->Fill(z2[i]);

	}

	h1->Draw();
	h2->SetLineColor(kRed);
	h2->Draw("same");

	TF1*f1 = new TF1("f1","gaus",-1.,1.);
	h1->Fit(f1,"M R","",-1.,1.);



}