void poincare(){
	float length= 9.8; 
	float g=9.8; 
	float q=0.5; 
	const int n = 150000; 
	//float F_DriveStep=0.01;
 	float time[n],theta[n],omega[n];
 	float Omega_D;
	float dt = 0.04;
	omega[0] = 0;
	time[0] = 0;
	theta[0]=0.2;
	Omega_D=2.0/3;
	//const int N=10;
	//float F_Drive[N];
	float F_Drive=0.5;
	float pi=3.1415;
    int nps = 0;

 	result5 = new TGraph();


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


	if(fabs(Omega_D*time[i]/(2*pi) - int (Omega_D*time[i]/(2*pi))<0.5*dt)){
	

		result5->SetPoint(nps,theta[i],omega[i]);
     	nps++;
     //result5->SetMarkerStyle(21);
     //result5->SetLineColor(kBlue);
	    //result5->Draw();

    }


	}		
// cout<<F_Drive[j]<<endl;
 //if(fabs(Omega_D*time[i]/(2*pi) - int (Omega_D*time[i]/(2*pi))<0.5*dt)){
   result6 = new TGraph(n,theta,omega);

	result6->SetTitle("Theta versus omega");
    result6->GetXaxis()->SetTitle("theta, [radians]");
    result6->GetYaxis()->SetTitle("omega, [radians/s]");
 	result6->SetLineColor(kRed);
	result6->Draw();
//}


     result5->SetMarkerStyle(20);
     result5->SetMarkerColor(kBlue);
	result5->Draw("sameP");

}
//else {
  
   

//}



 
 
     
