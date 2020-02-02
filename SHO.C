
void SHO(){
float length= 9.8; 
float g=9.8; 

float q=0; 
const int n = 1000; 
 float time[n],theta[n],omega[n],E1[n];
float dt = 0.04;
omega[0] = 0;
time[0] = 0;
theta[0]=0.2; 

//underdamped motion
for (int i=0;i<n-1;i++){


omega[i+1] = omega[i] - (g/length)*theta[i]*dt-q*omega[i]*dt;
theta[i+1] = theta[i]+omega[i+1]*dt;

time[i+1] = time[i] + dt;


  	E1[i+1] = omega[i+1]*omega[i+1] + theta[i+1] *theta[i+1];
  }	
   

    c = new TCanvas("c", "SHO", 0,0,1000,350);
    c->Divide(3);

    c_1->cd();
    result1 = new TGraph (n,time,theta);
   result1->SetTitle("Angles vs Time for SHM of a pendulum");
   result1->GetXaxis()->SetTitle("time, [s]");
   result1->GetYaxis()->SetTitle("theta, [radians]");
   result1->SetLineColor(kRed);
    result1->Draw("AL");

    c_2->cd();
    result2 = new TGraph (n,time,E1);
    result2->SetMinimum(0);
    result2->SetTitle("Energy vs Time for SHM of a pendulum");
   result2->GetXaxis()->SetTitle("time, [s]");
   result2->GetYaxis()->SetTitle("E1, [joules]");
    result2->Draw("AL");

    c_3->cd();
    result3 = new TGraph (n,theta,omega);
    result3->SetTitle("Phase space trajectory");
   result3->GetXaxis()->SetTitle("theta, [radians]");
   result3->GetYaxis()->SetTitle("omega, [radians/s]");
    result3->Draw("AL");




}