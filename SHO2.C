
	void SHO2(){

	float A0=2;
	const int n=500;
	float t[n],Theta[n],Omega[n],E[n],Theta1[n],Theta2[n],Omega1[n],Omega2[n];
	float EE[n],EEC[n],EERK[n];
	float Thetap, Omegap;
	float dt=0.01;
	float gl=1;

	t[0]=0;
	//EE[0]=0;
	Omega[0]=Omega1[0]=Omega2[0]=0;
	Theta[0]=Theta1[0]=Theta2[0]=A0;

	for(int i=0;i<n-1;i++){

		t[i+1] = dt*i;


		//Euler's method



	//Euler-Cromer calculations

	//Theta1[i+1] = Theta1[i] + (Omega1[i+1]*dt);
	Omega1[i+1] = Omega1[i] - (gl*Theta1[i]*dt);
	Theta1[i+1] = Theta1[i] + (Omega1[i+1]*dt);

	//Range Kutta method

	


	//Energy calculations
	//Euler's method

	
	//Euler Cromer's method
	EEC[i] = Omega1[i]*Omega1[i] + Theta1[i]*Theta1[i];
    //cout<<"Euler-Cromer "<<EEC[i]<<endl;
	
	}
//	EEC[n-1]=EEC[n-2];
//	EERK[n-1] = EERK[n-2];



  // graphE = new TGraph (n,t,Theta);
   //graphE->SetTitle("Angles vs Time for SHM of a pendulum");
   //graphE->GetXaxis()->SetTitle("t, [s]");
   //graphE->GetYaxis()->SetTitle("theta, [radians]");
   //graphE->SetLineColor(kRed);
   //graphE->Draw("Al");
  
 
 	graphEC = new TGraph (n,t,Theta1);
 	//graphEC->SetLineColor(kBlue);
 	  graphEC->SetTitle("Angles vs Time for SHM of a pendulum");
   graphEC->GetXaxis()->SetTitle("t, [s]");
   graphEC->GetYaxis()->SetTitle("theta, [radians]");
   graphEC->SetLineColor(kRed);
   graphEC->Draw("Al");
 	


//
 	//graphRK = new TGraph (n,t,Theta2);
 //	graphRK -> SetLineColor(kGreen);
 	//graphRK->Draw("samel");


 	//TF1*function = new TF1("function","A0*sin(t)",0,25);
 	//function->SetLineColor(kBlack);
 	//function->Draw("same");

 	leg = new TLegend(0.2,0.4,0.6,0.2);
	//leg->AddEntry(graphE,"Euler's method","l");
	leg->AddEntry(graphEC,"Euler's Cromer method","p");
	//leg->AddEntry(graphRK,"Range Kutta method","l");
	leg->Draw("same");

	c = new TCanvas ("c","range",100,100,700,600);
	c->Draw();
 

    graphEE = new TGraph (n-1,t,EE);
	graphEE->SetTitle("Energy vs Time for three methods");
   	graphEE->GetXaxis()->SetTitle("t, [s]");
   	graphEE->GetYaxis()->SetTitle("Energy, [Joules]");
   	graphEE->SetLineColor(kRed);
   	graphEE->Draw("Al");

   	 graphEERK = new TGraph (n-1,t,EERK);
   	graphEERK->SetLineColor(kGreen);
   	graphEERK->Draw("samel");

   	graphEEC = new TGraph (n-1,t,EEC);
   	graphEEC->SetLineColor(kBlue);
   	graphEEC->Draw("samel");

   	leg1 = new TLegend(0.2,0.4,0.6,0.2);
	leg1->AddEntry(graphEE,"Euler's method","l");
	leg1->AddEntry(graphEEC,"Euler's Cromer method","l");
	leg1->AddEntry(graphEERK,"Range Kutta method","l");
	leg1->Draw("same");
}