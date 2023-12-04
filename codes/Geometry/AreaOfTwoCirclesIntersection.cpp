llf ct(llf r, llf t){ // 0<=t<=2*pi
	llf t2=min(t, 2*pi-t), res=r*r/2*(t2-sin(t2));
	return t<pi?res:pi*r*r-res;
}
// area of line and circle (the smaller part)
llf cl(llf r, llf d){
	return ct(r, 2*acos(d/r));
}
// area of two circles
llf cc(llf r1, llf r2, llf d){ // r of c1, c2, distance between centers
	if(d>=r1+r2)return 0;
	if(d<eps)return pi*min(r1, r2)*min(r1, r2);
	llf t1=2*acos((r1*r1+d*d-r2*r2)/(2*r1*d)), t2=2*acos((r2*r2+d*d-r1*r1)/(2*r2*d));
	return ct(r1, t1)+ct(r2, t2);
}
