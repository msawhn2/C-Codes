void jupitereffect(){


const int n=150000;//1000000;//150000;//1000000;
float V_m_x[n],V_m_y[n],x_m[n],y_m[n],r_m[n],r_j[n],r_m_j[n],E[n],V[n],t[n];
float x_j[n],y_j[n],V_j_x[n],V_j_y[n];
float dt = 0.00003;//0.0001;//0.00003;//0.0001;
float pi = 3.1415; 
float GMs = 4*pi*pi;
float M_m=6.6*pow(10,23); 
float M_j=1000*1.9*pow(10,27);
float M_s=2*pow(10,30); 

x_m[0]=1; 
y_m[0]=0;
V_m_x[0]=0; 
V_m_y[0]=2*pi;

x_j[0]=5.2;
y_j[0]=0;
V_j_x[0]=0; 
V_j_y[0]= 2.7549; // This is 2*pi*5.2 AU/11.85 years = 2.75 AU/year

	
		for(int i=0;i<n;i++){

				r_m[i] = sqrt(x_m[i]*x_m[i] + y_m[i]*y_m[i]);

 				r_j[i] = sqrt(x_j[i]*x_j[i] + y_j[i]*y_j[i]);

 				r_m_j[i] = sqrt((x_m[i] - x_j[i])*(x_m[i] - x_j[i]) + (y_m[i] - y_j[i])*(y_m[i] - y_j[i]));


 	V_m_x[i+1] = V_m_x[i] - ((GMs*x_m[i]) / (r_m[i]*r_m[i]*r_m[i]))*dt - (GMs*(M_j/M_s)*(x_m[i] - x_j[i]))*dt/ (r_m_j[i]*r_m_j[i]*r_m_j[i]);

    V_m_y[i+1] = V_m_y[i] - ((GMs*y_m[i]) / (r_m[i]*r_m[i]*r_m[i]))*dt - (GMs*(M_j/M_s)*(y_m[i] - y_j[i]))*dt/ (r_m_j[i]*r_m_j[i]*r_m_j[i]);

    V_j_x[i+1] = V_j_x[i] - ((GMs*x_j[i]) / (r_j[i]*r_j[i]*r_j[i]))*dt - (GMs*(M_m/M_s)*(x_j[i] - x_m[i]))*dt/ (r_m_j[i]*r_m_j[i]*r_m_j[i]);

   V_j_y[i+1] = V_j_y[i] - ((GMs*y_j[i]) / (r_j[i]*r_j[i]*r_j[i]))*dt - (GMs*(M_m/M_s)*(y_j[i] - y_m[i]))*dt/ (r_m_j[i]*r_m_j[i]*r_m_j[i]);

 
 // V_m_x[i+1] = V_m_x[i] - ((GMs*x_m[i]) / (r_m[i]*r_m[i]*r_m[i]))*dt - (GMs*(M_m)*(x_m[i] - x_j[i]))*dt/ (r_m_j[i]*r_m_j[i]*r_m_j[i]);

 //    V_m_y[i+1] = V_m_y[i] - ((GMs*y_m[i]) / (r_m[i]*r_m[i]*r_m[i]))*dt - (GMs*(M_m)*(y_m[i] - y_j[i]))*dt/ (r_m_j[i]*r_m_j[i]*r_m_j[i]);

 //    V_j_x[i+1] = V_j_x[i] - ((GMs*x_j[i]) / (r_j[i]*r_j[i]*r_j[i]))*dt - (GMs*(M_j)*(x_j[i] - x_m[i]))*dt/ (r_m_j[i]*r_m_j[i]*r_m_j[i]);

 //   V_j_y[i+1] = V_j_y[i] - ((GMs*y_j[i]) / (r_j[i]*r_j[i]*r_j[i]))*dt - (GMs*(M_j)*(y_j[i] - y_m[i]))*dt/ (r_m_j[i]*r_m_j[i]*r_m_j[i]);


 x_m[i+1] = x_m[i] + V_m_x[i+1]*dt;

 y_m[i+1] = y_m[i] + V_m_y[i+1]*dt;

 x_j[i+1] = x_j[i] + V_j_x[i+1]*dt;

 y_j[i+1] = y_j[i] + V_j_y[i+1]*dt;

// cout<<y_j[i+1]<<endl;

		}

		gr1 = new TGraph(n-1,x_j,y_j);
		gr1->SetTitle("Effect of Jupiter on Mars (1000Mj)");
		gr1->GetXaxis()->SetTitle("x, [AU]");
		gr1->GetYaxis()->SetTitle("y, [AU]");
		gr1->SetLineColor(kRed);
		 // gr1->GetXaxis()->SetRangeUser(-5,5);
		gr1->GetYaxis()->SetRangeUser(-8,6);
		gr1->Draw("AL");

		gr2 = new TGraph(n-1,x_m,y_m);
		gr2->SetLineColor(kBlue);
		gr2->Draw("same");

	}