void lyapunov(){
	float length= 9.8; 
float g=9.8; 
float q=0.5; 
const int n = 2000; 
 float time[n],theta1[n],theta2[n],omega1[n],omega2[n],detheta[n],delta[n];
 float Omega_D;
float dt = 0.04;
omega1[0] = 0;
omega2[0] = 0;
time[0] = 0;
theta1[0]=0.2;
theta2[0]=0.199;
Omega_D=2.0/3;
float F_Drive=0.5;
float pi=3.1415;
float slope[n];

 	
	for(int i=0;i<n-1;i++){
		


	omega1[i+1] = omega1[i] - (g/length)*sin(theta1[i])*dt - q*omega1[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	omega2[i+1] = omega2[i] - (g/length)*sin(theta2[i])*dt - q*omega2[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	theta1[i+1] = theta1[i] + omega1[i+1]*dt;
	//cout<<theta1[i+1]<<endl;
	//cout<<"theta 2 "<<theta2[i+1]<<endl;
	theta2[i+1] = theta2[i] + omega2[i+1]*dt; 
	

	time[i+1] = time[i] + dt;

	if((theta1[i+1]) || (theta2[i+1] )>pi)
	{
		theta1[i+1]-=2*pi;
		theta2[i+1]-=2*pi;
	}
	if ((theta1[i+1]) || (theta2[i+1] )<-1.0*pi)
	{
		theta1[i+1]+=2*pi;
		theta2[i+1]+=2*pi;
	}

	detheta[i] =  theta2[i+1] - theta1 [i+1];

	delta[i] = fabs(detheta[i]);

    //cout<<delta[i]<<" "<<time[i+1]<<endl;
	slope[i] = delta[i+1]-delta[i]/time[i+1]-time[i];
    cout<<slope[i]<<endl;
	
}
    //cout<<slope[i]<<endl;  
	c = new TCanvas("c", "SHO", 0,0,700,600);
	gPad->SetLogy(1);
    result = new TGraph(n-1,time,delta);
	result->SetTitle("delta Theta versus time");
	//result->SetLogy(1);
    //result->SetMinimum(0.0001);
    //result->SetMaximum(10);
    result->GetXaxis()->SetTitle("time, [seconds]");
    result->GetYaxis()->SetTitle("delta theta, [radians]");
	result->SetLineColor(kRed);
	result->Draw();
	
    //result4 = new TGraph(n-1,time,slope)
    //result4->Draw("same");
		
 	F_Drive=1.2;
 	for(int i=0;i<n-1;i++){
		


	omega1[i+1] = omega1[i] - (g/length)*sin(theta1[i])*dt - q*omega1[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	omega2[i+1] = omega2[i] - (g/length)*sin(theta2[i])*dt - q*omega2[i]*dt +  F_Drive*sin(time[i]*Omega_D)*dt;
	theta1[i+1] = theta1[i] + omega1[i+1]*dt;
	//cout<<theta1[i+1]<<endl;
	//cout<<"theta 2 "<<theta2[i+1]<<endl;
	theta2[i+1] = theta2[i] + omega2[i+1]*dt; 
	

	time[i+1] = time[i] + dt;

	if((theta1[i+1]) || (theta2[i+1] )>pi)
	{
		theta1[i+1]-=2*pi;
		theta2[i+1]-=2*pi;
	}
	if ((theta1[i+1]) || (theta2[i+1] )<-1.0*pi)
	{
		theta1[i+1]+=2*pi;
		theta2[i+1]+=2*pi;
	}

	detheta[i] =  theta2[i+1] - theta1 [i+1];

	delta[i] = fabs(detheta[i]);
	//cout<<delta[i]<<" "<<time[i+1]<<endl;
	//slope[i] = delta[i+1]-delta[i]/time[i+1]-time[i];
    //cout<<slope[i]<<endl;
	
  
}

	d = new TCanvas("d", "SHO", 0,0,700,600);
	gPad->SetLogy(1);
    result = new TGraph(n-1,time,delta);
	result->SetTitle("delta Theta versus time");
    result->GetXaxis()->SetTitle("time, [seconds]");
    result->GetYaxis()->SetTitle("delta theta, [radians]");
	result->SetLineColor(kRed);
	result->Draw();
	

	
	








}