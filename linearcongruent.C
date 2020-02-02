void linearcongruent(){
	
	const int M = 2147483647;//9;
	const int a = 16807;//4;
	const int c=0;//1;
	const int n = 10000000;
	int x,y;
	float xkk;

	x = 3;
	y = 2;


	TH1D *h1 = new TH1D("h1","h1",100,0,1.);
	TH1D *h2 = new TH1D("h2","h2",100,0,1.);

	h1->Sumw2();
	h1->SetMinimum(0);
	h2->Sumw2();
	h2->SetMinimum(0);

	for(int i=0;i<n;i++){

            x = (a*x + c) % M;   
            y = (a*y + c) % M;   
			h1->Fill(1.0*x/(M-1));
			h2->Fill(1.0*y/(M-1));
			
	}

	
	h1->SetTitle("Linear Congruent Method");
   	h1->GetYaxis()->SetTitle("yi");
   	h1->GetXaxis()->SetTitle("xi");	
	h1->SetLineColor(kBlue);
	h2->SetLineColor(kRed);
	h1->Draw();
	h2->Draw("same");


     leg = new TLegend(0.25,0.3,0.75,0.4);
	leg->AddEntry(h1,"Random distribution of xi","l");
	leg->AddEntry(h2,"Random distribution of yi","l");
	leg->Draw("same");
 
for(int i=0;i<1000;i++){

			
           x = (a*x + c) % M;  
			xkk += pow(x,5)/n;
			
	}	


	cout<<"The 5th moment of this distribution is "<<1/6.<<endl;

}


