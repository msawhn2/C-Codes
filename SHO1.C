void SHO1(){

//underdamped motion
float length= 9.8; 
float g=9.8; 

float q=0.5; 
const int n = 1000; 
 float time[n],theta[n],omega[n];
float dt = 0.04;
omega[0] = 0;
time[0] = 0;
theta[0]=0.2; 

//underdamped motion
for (int i=0;i<n-1;i++){


omega[i+1] = omega[i] - (g/length)*theta[i]*dt-q*omega[i]*dt;
theta[i+1] = theta[i]+omega[i+1]*dt;

time[i+1] = time[i] + dt;
}
 result1 = new TGraph(n,time,theta);
 result1->SetTitle("Angles vs Time for damped and driven motion of a pendulum");
   result1->GetXaxis()->SetTitle("time, [s]");
   result1->GetYaxis()->SetTitle("theta, [radians]");
   result1->SetLineColor(kRed);
   result1->SetMinimum(-2);
result1->SetMaximum(2);
   result1->Draw("AL");

//critically damped motion 
   q=2;
   for (int i=0;i<n-1;i++){


omega[i+1] = omega[i] - (g/length)*theta[i]*dt-q*omega[i]*dt;
theta[i+1] = theta[i]+omega[i+1]*dt;

time[i+1] = time[i] + dt;
}
 result2 = new TGraph(n,time,theta);
   result2->SetLineColor(kGreen);
   result2->Draw("same");

//over-damped motion
   q=5;

   for (int i=0;i<n-1;i++){


omega[i+1] = omega[i] - (g/length)*theta[i]*dt-q*omega[i]*dt;
theta[i+1] = theta[i]+omega[i+1]*dt;

time[i+1] = time[i] + dt;
}
 result3 = new TGraph(n,time,theta);
   result3->SetLineColor(kBlue);
   result3->Draw("same");

float F_Drive=0.5; 
float q=1;
const int N= 20;
float Omega_D[N], amax[N];
float Omega0=.5;
//const int n1=1500;
float temporary_theta_step_plus_1;
dt = 0.05;
float OmegaStep = 0.1;

float pi=3.1415;
//n=2500;
q=0.5;

for(int j=0;j<N;j++){

  Omega_D[j] = Omega0 + OmegaStep*j;
for(int i=0;i<n-1;i++){

omega[i+1] = omega[i] - (g/length)*theta[i]*dt-q*omega[i]*dt + F_Drive*sin(time[i]*Omega_D[j])*dt;
theta[i+1] = theta[i]+omega[i+1]*dt; 

time[i+1] = time[i] + dt;

if((time[i]>10)&& (theta[i+1]<theta[i]) && (theta[i]>theta[i-1])){
amax[j]=theta[i];
cout<<amax[j]<<endl;

}

}


//}
result4 = new TGraph(n,time,theta);

result4->SetLineColor(1+j);
result4->Draw("sameL");


}

c = new TCanvas("c", "SHO", 0,0,1000,350);
w1 = new TGraph(N,Omega_D,amax);
w1->SetTitle("max amplitude vs driven frequency for damped and driven motion of a pendulum");
   w1->GetXaxis()->SetTitle("omega_D, [rad/s]");
   w1->GetYaxis()->SetTitle("amplitude, [radians]");
w1->SetLineColor(kGreen);
w1->Draw();

}
