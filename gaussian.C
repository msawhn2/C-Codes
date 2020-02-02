void gaussian(){
	
	const int N =3;
	float a0[N][N] = {2,4,2,1,1,1,3,-3,6};
	float b[N] = {8,3,6};
	float b[N],x[N];
	float sum,tempa,tempb;

	for(int k=0;k<N-1;k++){
		for(int i=k;i<N;i++){

			tempa = a0[i][k];

			for(int j=k;j<N;j++){

				if(tempa!=0)
					a0[i][j] = a0[i][j] /tempa;

				else
					{cout<<"Division by zero";
						return;
					}
			}

			tempb = b[k];

			for(int i=k+1; i<N; i++){

				for(int j=k;j<N;j++){

					a0[i][j]-=a0[k][j];
				}
				b[i] - = tempb;
			}
		}


		x[N-1] = (1/(a0[N-1][N-1]))*b[N-1];
		x[N-2] = (1/(a0[N-2][N-2]))*(b[N-2]-a0[N-2][N-1]*x[N-1]);

		for(int j=0;j<N;j++){

			sum = sum + a0[0][j]*x[j];
		}

			x[0] = (1/a0[0][0])*(b[0]-sum);

			for(int j=0;j<N;j++){
				cout<<"x_"<<j+1<<" = "<<x[j]<<endl;
			}
	
	}
}