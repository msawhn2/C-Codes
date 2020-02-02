void rejection(){
	
	const int nmax = 100000;
	float dx = 0.01;
	float c = 300;
	float dt = 0.00003;
	float r2;
	float y[nmax];
	float x[nmax];
	const int time = 100;
	float pi = 3.1415;
	float z1[nmax],z2[nmax],t[nmax];


		
		

	
	TF1*f1 = new TF1("f1","exp(-1.0*[0]*(x-[1])*(x-[1]))",-1.,1.);
	f1->SetParameters(1000,0.3);
	// f1->SetLineColor(2);
	f1->Draw();
	// h1->Fit(f1,"M R","",-1.,1.);

	TH1D *h1 = new TH1D("h1","h1",100,0,1.);
	// TH1D *h2 = new TH1D("h2","h2",100,-1.,1.);
	h1->Sumw2();
	// h2->Sumw2();
	h1->SetMinimum(0);
	// h2->SetMinimum(0);



	for(int i=0; i<nmax-1;i++){

		x[i] =  gRandom->Rndm();
		y[i] =  gRandom->Rndm();
		
		t[i] = f1->Eval(x[i]);
		// cout<<t[i]<<endl;
		// cout<<"y "<<y[i]<<endl;
		if(t[i]>y[i]){
			// cout<<"rejection"<<endl;

		h1->Fill(x[i]);
		// h2->Fill(z2[i]);
	}
	
}
	h1->Draw();
	// h2->SetLineColor(kRed);
 h1->Fit("gaus");
	// f1->Draw("same");





}
