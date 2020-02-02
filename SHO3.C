void SHO3(){

 
float length= 9.8; 
float g=9.8; 
float q=0.5; 
const int n = 1500; 
 float time[n],theta[n],omega[n];
 float Omega_D;
float dt = 0.04;
omega[0] = 0;
time[0] = 0;
theta[0]=0.2;
Omega_D=2.0/3;
float F_Drive=1.2;
float pi=3.1415;

 	
	for(int i=0;i<n-1;i++){
		


	omega[i+1] = omega[i] - (g/length)*sin(theta[i])*dt - q*omega[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	theta[i+1] = theta[i]+omega[i+1]*dt; 

	if(theta[i+1]>pi)
	{
		theta[i+1]-=2*pi;
	}
	if (theta[i+1]<-1.0*pi)
	{
		theta[i+1]+=2*pi;
	}

	time[i+1] = time[i] + dt;

}
	result = new TGraph(n,time,theta);
	result->SetTitle("Theta versus time");
   result->GetXaxis()->SetTitle("time, [seconds]");
   result->GetYaxis()->SetTitle("theta, [radians]");
	result->SetLineColor(kRed);
	result->Draw();


   F_Drive=0.5;
   for(int i=0;i<n-1;i++){
		


	omega[i+1] = omega[i] - (g/length)*sin(theta[i])*dt - q*omega[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	theta[i+1] = theta[i]+omega[i+1]*dt; 

	if(theta[i+1]>pi)
	{
		theta[i+1]-=2*pi;
	}
	if (theta[i+1]<-1.0*pi)
	{
		theta[i+1]+=2*pi;
	}

	time[i+1] = time[i] + dt;

}
	result1 = new TGraph(n,time,theta);
	result1->SetLineColor(kBlue);
	result1->Draw("sameL");

	F_Drive=0;

	for(int i=0;i<n-1;i++){
		


	omega[i+1] = omega[i] - (g/length)*sin(theta[i])*dt - q*omega[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	theta[i+1] = theta[i]+omega[i+1]*dt; 

	if(theta[i+1]>pi)
	{
		theta[i+1]-=2*pi;
	}
	if (theta[i+1]<-1.0*pi)
	{
		theta[i+1]+=2*pi;
	}

	time[i+1] = time[i] + dt;

}
   result2 = new TGraph(n,time,theta);
	result2->SetLineColor(kGreen);
	result2->Draw("sameL");

leg = new TLegend(0.2,0.3,0.6,0.2);
	leg->AddEntry(result2,"F_Drive=0","l");
	leg->AddEntry(result1,"F_Drive=0.5","l");
	leg->AddEntry(result,"F_Drive=1.2","l");
	leg->Draw("same");


	c = new TCanvas("c", "SHO", 0,0,1000,350);
	F_Drive=1.2;

	for(int i=0;i<n-1;i++){
		


	omega[i+1] = omega[i] - (g/length)*sin(theta[i])*dt - q*omega[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	theta[i+1] = theta[i]+omega[i+1]*dt; 

	if(theta[i+1]>pi)
	{
		theta[i+1]-=2*pi;
	}
	if (theta[i+1]<-1.0*pi)
	{
		theta[i+1]+=2*pi;
	}

	time[i+1] = time[i] + dt;

}
	w1 = new TGraph(n,time,omega);
	w1->SetTitle("omega versus time");
     w1->GetXaxis()->SetTitle("time, [seconds]");
   w1->GetYaxis()->SetTitle("omega, [radians/s]");
	w1->SetLineColor(kRed);
	w1->Draw();

	F_Drive=0.5;
	for(int i=0;i<n-1;i++){
		


	omega[i+1] = omega[i] - (g/length)*sin(theta[i])*dt - q*omega[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	theta[i+1] = theta[i]+omega[i+1]*dt; 

	if(theta[i+1]>pi)
	{
		theta[i+1]-=2*pi;
	}
	if (theta[i+1]<-1.0*pi)
	{
		theta[i+1]+=2*pi;
	}

	time[i+1] = time[i] + dt;

}
	w2 = new TGraph(n,time,omega);
	w2->SetTitle("omega versus time");
    w2->GetXaxis()->SetTitle("time, [seconds]");
    w2->GetYaxis()->SetTitle("omega, [radians/s]");
	w2->SetLineColor(kBlue);
	w2->Draw("sameL");

	F_Drive=0;
	for(int i=0;i<n-1;i++){
		


	omega[i+1] = omega[i] - (g/length)*sin(theta[i])*dt - q*omega[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	theta[i+1] = theta[i]+omega[i+1]*dt; 

	if(theta[i+1]>pi)
	{
		theta[i+1]-=2*pi;
	}
	if (theta[i+1]<-1.0*pi)
	{
		theta[i+1]+=2*pi;
	}

	time[i+1] = time[i] + dt;

}
	w3 = new TGraph(n,time,omega);
	w3->SetTitle("omega versus time");
    w3->GetXaxis()->SetTitle("time, [seconds]");
    w3->GetYaxis()->SetTitle("omega, [radians/s]");
	w3->SetLineColor(kGreen);
	w3->Draw("sameL");

	leg = new TLegend(0.2,0.3,0.6,0.2);
	leg->AddEntry(w3,"F_Drive=0","l");
	leg->AddEntry(w2,"F_Drive=0.5","l");
	leg->AddEntry(w1,"F_Drive=1.2","l");
	leg->Draw("same");

 d= new TCanvas("d", "SHO", 0,0,1000,350);
	F_Drive=1.2;

	for(int i=0;i<n-1;i++){
		


	omega[i+1] = omega[i] - (g/length)*sin(theta[i])*dt - q*omega[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	theta[i+1] = theta[i]+omega[i+1]*dt; 


	time[i+1] = time[i] + dt;

}
	result3 = new TGraph(n,time,theta);
	result3->SetTitle("Theta versus time");
   result3->GetXaxis()->SetTitle("time, [seconds]");
   result3->GetYaxis()->SetTitle("theta, [radians]");
	result3->SetLineColor(kRed);
	result3->Draw();



 	
	for(int i=0;i<n-1;i++){
		


	omega[i+1] = omega[i] - (g/length)*sin(theta[i])*dt - q*omega[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	theta[i+1] = theta[i]+omega[i+1]*dt; 

	if(theta[i+1]>pi)
	{
		theta[i+1]-=2*pi;
	}
	if (theta[i+1]<-1.0*pi)
	{
		theta[i+1]+=2*pi;
	}

	time[i+1] = time[i] + dt;

}
	result4 = new TGraph(n,time,theta);
	result4->SetLineColor(kBlue);
	result4->Draw("sameL");


   e= new TCanvas("e", "SHO", 0,0,700,600);
	F_Drive=1.2;

	for(int i=0;i<n-1;i++){
		


	omega[i+1] = omega[i] - (g/length)*sin(theta[i])*dt - q*omega[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	theta[i+1] = theta[i]+omega[i+1]*dt; 

	if(theta[i+1]>pi)
	{
		theta[i+1]-=2*pi;
	}
	if (theta[i+1]<-1.0*pi)
	{
		theta[i+1]+=2*pi;
	}



	time[i+1] = time[i] + dt;

}
	result5 = new TGraph(n,theta,omega);
	result5->SetTitle("Theta versus omega");
   result5->GetXaxis()->SetTitle("theta, [radians]");
   result5->GetYaxis()->SetTitle("omega, [radians/s]");
	result5->SetLineColor(kRed);
	result5->Draw();


 f= new TCanvas("f", "SHO", 0,0,700,600);
	F_Drive=0.5;

	for(int i=0;i<n-1;i++){
		


	omega[i+1] = omega[i] - (g/length)*sin(theta[i])*dt - q*omega[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	theta[i+1] = theta[i]+omega[i+1]*dt; 

	if(theta[i+1]>pi)
	{
		theta[i+1]-=2*pi;
	}
	if (theta[i+1]<-1.0*pi)
	{
		theta[i+1]+=2*pi;
	}



	time[i+1] = time[i] + dt;

}
	result6 = new TGraph(n,theta,omega);
	result6->SetTitle("Theta versus omega");
   result6->GetXaxis()->SetTitle("theta, [radians]");
   result6->GetYaxis()->SetTitle("omega, [radians/s]");
	result6->SetLineColor(kRed);
	result6->Draw();


}

