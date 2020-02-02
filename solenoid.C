void solenoid(){
	


	const int n = 1000;
	const int N = 10;
	const int turns = 10;
	const float pi = 3.14159265;
	int i, j, k, l;
	// float L = 10.;
	float Bx,By,Bz; 
	float x[2 * N] = {0.};
	// float y[N] = {0.};
	float z[N] = {0.};
	float y=0;
	float rx;
	float ry;
	float rz;
	float r;
	float dlx, dly, dlz;
	float R = 0.55;
	float dTheta = (2 * pi)/(N-1);
	float L = 2.0*R;
	float theta = 0.;
	float xw, yw, zw;
	float cz = 0.1*R;
	float dzw = cz/N;

	float C = 1./(4.*pi);
  	
  	 float dz,dx;
dz = (2*L)/(N-1);
  dx = (2*L)/(N-1);

  	
c = new TCanvas("c", "B field", 0,0,800,700);
c->Draw();

// dz = (2*L)/(N-1);
//   dx = (2*L)/(N-1);


gStyle->SetOptStat(0);	
hist2 = new TH2D("hist1", "Magnetic field in the x-z plane", N, -L-dx, L+dx, N, -L-dx, L+dx);
hist2->GetXaxis()->SetTitle("Z");
  	hist2->GetYaxis()->SetTitle("X");
	hist2->Draw("");

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
    			// if (i == 0) gr->SetPoint(k , z[k], Bz);
    		//gr->SetTitle("Magnetic Field due to a Wire; Distance From Wire (m); Magnetic Field (B)");
    		
    			

	}

	// gr1 = new TArrow(x[i],z[k],x[i]+Bx[i]/1000,z[k]+Bz[i]/1000);
	gr1 = new TArrow(z[k],x[i],z[k]+Bz[i]/200,x[i]+Bx[i]/200);
			gr1->SetArrowSize(0.015);
			gr1->Draw();
	
	}
}


}

