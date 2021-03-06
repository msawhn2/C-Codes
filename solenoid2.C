void solenoid2(){


const int n = 1000;
	const int N = 10;
	const int turns = 80;
	const float pi = 3.14159265;
	int i, j, k, l;
	// float L = 10.;
	float Bx,By,Bz; 
	float x[2 * turns] = {0.};
	// float y[N] = {0.};
	float z[turns] = {0.};
	float y=0;
	float rx;
	float ry;
	float rz;
	float r;
	float dlx, dly, dlz;
	float R = 0.5;
	float dTheta = (2 * pi)/(N-1);
	float L = 3.0*R;
	float theta = 0.;
	float xw, yw, zw;

	float C = 1./(4.*pi);
  	
  	 float dz,dx;
dz = (2*L)/(N-1);
  dx = (2*L)/(N-1);
	



gr = new TGraph ();


for (int i=0;i<turns;i++){
	x[i] = -L + dx*i;

	for (int k=0;k<N;k++){

	z[k] = -L + dz*k;

	if((fabs(x[i])==R) && (z[k] > -1.0*R) &&(z[k] < R)){
	 continue;
	}
	// if((fabs(x[i])==R) && (z[k] == 0)){
	//  continue;
	// }
	Bx[i] = 0; Bz[i] = 0; By[i] = 0;

	for(int l =0; l<n; l++){

		
    			theta = l * dTheta;

    			dlx = -1.*R * dTheta * sin(theta);
    			dly = R * dTheta * cos(theta);
    			dlz = R * dTheta * tan(theta);

    			xw = R * cos(theta);
    			yw = R * sin(theta);
    			zw = R * tan(theta);

    			rx = x[i] - xw;
    			ry = y - yw;
    			rz = z[k] - zw;

    			r = sqrt((rx * rx) + (ry * ry) + (rz * rz));
    			

    			Bx[i]= Bx[i] + C * ((dly * rz) / (r*r*r));
    			By[i] = By[i] - C * ((dlx * rz) / (r*r*r));
    			//Bz[k] = Bz[k] + C * (R * R * dTheta / pow((R * R + rz * rz), 3./2.));
    			Bz[i] = Bz[i] + C * (( (dlx * ry)-(dly*rx))/ (r*r*r));
}
    		// 	 gr->SetPoint(k , z[k], Bz);
    		// gr->SetTitle("Magnetic Field due to a Solenoid; Distance From Wire (m); Magnetic Field (B)");
    		
    		
    		}
    		}



// gr = new TGraph(N,z,Bz);

 gr->SetMarkerStyle(20);


	
exact = new TF1("exact", "([0]*[1]*[2])/x",0,2*n);
exact->SetParameter(0, 1.); //mu_knot
	exact->SetParameter(1, turns);
	exact->SetParameter(2, 1);//current -> mu*turns*I/R
	exact->SetTitle("Magnetic field of a solenoid vs z");
	exact->GetXaxis()->SetTitle("z [m]");
	exact->GetYaxis()->SetTitle("Bz");
	exact->SetLineColor(kRed);
	exact->GetYaxis()->SetLimits(-3,3);
	// exact->Draw();
// gr->Draw("same");
	// gr->Draw();
	exact->Draw();
	// gr->Draw();

}
