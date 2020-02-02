void ppendulum(){
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


	time[i+1] = time[i] + dt;

}
	result = new TGraph(n,time,theta);
	result->SetTitle("Theta versus time");
   result->GetXaxis()->SetTitle("time, [seconds]");
   result->GetYaxis()->SetTitle("theta, [radians]");
	result->SetLineColor(kRed);
	result->Draw();



 	
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

}