#include<stdio.h>

int main(){
	int i,a[100],j;
	scanf("%d", &a[0]);
	i=0; 
	while (a[i]>=0 && a[i]<=9){
			i++;
		scanf("%d",&a[i]);
	}
	printf("%d \n",i)	;
for (j=0;j<i;j++){
	printf("%d ",a[j]);
}

return(0);
}