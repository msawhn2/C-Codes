void string(){
	const int nmax = 100;
	float dx = 0.01;
	float c = 300;
	float dt = 0.0003;
	float r2;
	float y[nmax][3];


	for(int i=1;i<nmax;i++){

		y[i][1] = 0;
		y[i][2] = 0;
		y[i][3] = 0;

	} 


	for(int i=2; i<nmax-1;i++){

		y[i][2] = exp(-1000*(i*dx - 0.3*nmax*dx)*(i*dx - 0.3*nmax*dx));
		y[i][1] = exp(-1000*(i*dx - 0.3*nmax*dx)*(i*dx - 0.3*nmax*dx));

	}

	r2 = (dt*c/dx)*(dt*c/dx);


	for(int i=1;i<nmax-1;i++){

		y[i][3] = r2*(y[i+1][2] + y[i-1][2]) + 2*(1.0-r2)*y[i][2] - y[i][1];

		for(int i=1;i<nmax-1;i++){

			y[i][1] = y[i][2];
			y[i][2] = y[i][3];
		}
	}

	// gr = new TGraph ()

}