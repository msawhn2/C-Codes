void pointcharge(){
	
	const int n = 9;
	int i, j, k, l;
	float dx, dy;
	float v[n][n][n];
	float vNew[n][n][n];
	float dv = 0; 
	float Ex[n][n];
	float Ey[n][n];
	dx = fabs(-1. - 1.)/(n-1);
	dy = fabs(-1. - 1.)/(n-1);

	//set initial conditions
	for (k = 0; k < n; k++){
		for (j = 0; j < n; j++){
			for (i = 0; i < n; i++){
				v[k][j][i] = vNew[k][j][i] = 0;
				if (k == n/2 && j == n/2 && i == n/2) {
					v[k][j][i] = vNew[k][j][i] = 1;
				}
			}
		}
	}
	
	//print inital potential field
	for (k = 0; k < n; k++){
		cout<<"k: "<<k<<endl;
		for (j = 0; j < n; j++){
			for (i = 0; i < n; i++){
				printf("%.2f ", v[k][j][i]);
			}
			cout<<endl;
		}
		cout<<endl;
	}


	//relaxation calculation
	for (l = 0; l < 200; l++){
		dv = 0;
		for (k = 1; k < n-1; k++){
			for (j = 1; j < n-1; j++){
				for (i = 1; i < n-1; i++){

					vNew[k][j][i] = 1./6 * (v[k-1][j][i] + v[k+1][j][i] + v[k][j-1][i] + v[k][j+1][i] + v[k][j][i-1] + v[k][j][i+1]);			
					if (k == n/2 && j == n/2 && i == n/2) {continue;}

					dv = dv + fabs(vNew[k][j][i] - v[k][j][i]);
					v[k][j][i] = vNew[k][j][i];

				}
			}
		}
		
		if (dv <= 0.000000001) { cout<<"break, l = "<<l<<endl; break; }
	}

	//print final potential field
	for (k = 0; k < n; k++){
		cout<<"k: "<<k<<endl;
		for (j = 0; j < n; j++){
			// cout<<"j: "<<j<<", ";
			for (i = 0; i < n; i++){
				printf("%.3f ", v[k][j][i]);
			}
			cout<<endl;
		}
		cout<<endl;
	}
// gStyle->SetOptStat(0);
	for (k=1; k<= n/2; k++){
		// cout<<"K: "<<k<<endl;
		hist1 = new TH2D("hist1", "potential field", n, -1, 1, n, -1, 1);
		hist1->Draw("");
		for (j = 1; j < n-1; j++) {
			for (i = 1; i < n-1; i++) {

				hist->SetBinContent(i+1, j+1, v[k][j][i]);
		}
	}
}
	gStyle->SetOptStat(0);
	hist->Draw("surf2");


}