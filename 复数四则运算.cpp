#include<stdio.h>
struct fushu{
	float xb;
	float yb;
};
struct fushu one(struct fushu x,struct fushu y){
	struct fushu pr;
	pr.xb=x.xb+y.xb;
	pr.yb=x.yb+y.yb;
	return pr;
}
struct fushu tow(struct fushu x,struct fushu y){
	struct fushu pr2;
	pr2.xb=x.xb-y.xb;
	pr2.yb=x.yb-y.yb;
	return pr2;
}
struct fushu three(struct fushu x,struct fushu y){
    struct fushu pr3;
	pr3.xb=x.xb*y.xb-x.yb*y.yb;
	pr3.yb=x.xb*y.yb+x.yb*y.xb;
	return pr3;
}
struct fushu four(struct fushu x,struct fushu y){
	struct fushu pr4;
	pr4.xb=(x.xb*y.xb+x.yb*y.yb)/(y.xb*y.xb+y.yb*y.yb);
	pr4.yb=(x.yb*y.xb-x.xb*y.yb)/(y.xb*y.xb+y.yb*y.yb);
	return pr4;
}
void shizi(float x,float y){
	if(y<0){
		printf("(%.1f%.1fi)",x,y);
	}else printf("(%.1f+%.1fi)",x,y);
}
void result(float x,float y){
	if(y<0.05&&y>-0.05){
		printf("%.1f\n",x);
	}else if(x<0.05&&x>-0.05){
		printf("%.1fi\n",y);
	}
	else if(y<0){
		printf("%.1f%.1fi\n",x,y);
	}else printf("%.1f+%.1fi\n",x,y);
}
int main(){
	struct fushu c1,c2,r1,r2,r3,r4;
	scanf("%f %f %f %f",&c1.xb,&c1.yb,&c2.xb,&c2.yb);
	r1=one(c1,c2);
	shizi(c1.xb,c1.yb);
	printf(" + ");
	shizi(c2.xb,c2.yb);
	printf(" = ");
	result(r1.xb,r1.yb);
	r2=tow(c1,c2);
	shizi(c1.xb,c1.yb);
	printf(" - ");
	shizi(c2.xb,c2.yb);
	printf(" = ");
	result(r2.xb,r2.yb);
	r3=three(c1,c2);
	shizi(c1.xb,c1.yb);
	printf(" * ");
	shizi(c2.xb,c2.yb);
	printf(" = ");
	result(r3.xb,r3.yb);
	r4=four(c1,c2);
	shizi(c1.xb,c1.yb);
	printf(" / ");
	shizi(c2.xb,c2.yb);
	printf(" = ");
	result(r4.xb,r4.yb);
}


