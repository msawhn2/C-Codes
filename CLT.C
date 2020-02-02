void CLT(){


	const int n=10000;


	// TF1 //define TF1 using Gauss
	
	TH1D *h1 = new TH1D("h1","h1",100,0,1.);
	h1->Sumw2();
	h1->SetMinimum(0);
//	gStyle->SetOptFit(0001);


for(int j=0;j<n;j++){

	float xk =0;

	for(int i=0;i<12;i++){

	float x = gRandom->Rndm();
	// cout<<x<<endl;
	xk+=x;
	

	

	}

  h1->Fill(xk/12.);
 


}
	h1->Draw();

	h1->Fit("gaus");
}
