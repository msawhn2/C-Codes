void correlation(){
	
	const int M = 2147483647;//9;
	const int a = 16807;//4;
	const int c=0;//1;
	const int n = 1000;
	int x[n+5];
	float xkk;
	int sum[n+5];


	x[0] = 3;
	sum[0] =0 ;
	TH1D *h1 = new TH1D("h1","h1",100,0,1.);
	h1->Sumw2();
	h1->SetMinimum(0);

	for(int i=0;i<n-1;i++){

            x[i] = (a*x[i] + c) % M;   
            // sum[i] += x[i]*x[i+4];
			// h1->Fill(1.0*x[i]/(M-1),sum[i]);

			
	}

	for(int i=0;i<n-1;i++){

		 sum[i] += x[i]*x[i+3];
			h1->Fill(1.0*x[i]/(M-1),sum[i]);

	}

	
	h1->SetTitle("Linear Congruent Method");
   	h1->GetYaxis()->SetTitle("xi+4");
   	h1->GetXaxis()->SetTitle("xi");	
	h1->Draw();


}