void lc1(){

	const int M = 2147483647;//9;
	const int a = 16807;//4;
	const int c=0;//1;
	const int n = 10000000;
	int x,y;
	float xkk;

	x = 3;
	y=3;

	TH2D *h1 = new TH2D("h1","h1",100,0,1.,100,0,1.);
	// TH2D *h2 = new TH2D("h2","h2",100,0,1.,100,0,1.);
	h1->Sumw2();
	h1->SetMinimum(0);
	// h2->Sumw2();
	// h2->SetMinimum(0);


	for(int i=0;i<n;i++){

            x = (a*x + c) % M;  
            // y = (a*y + c) % M;  

			h1->Fill(1.0*x/(M-1));
			// h2->Fill(1.0*y/(M-1));

			
	}

	
	h1->SetTitle("Linear Congruent Method");
   	h1->GetYaxis()->SetTitle("yi");
   	h1->GetXaxis()->SetTitle("xi");	
	h1->Draw();
	// h2->SetLineColor(kRed);
	// h2->Draw("same");


}