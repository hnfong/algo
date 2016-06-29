program p1014;
var
	i,j,k,p,q,n,r,a,b,v,e,x,y,z : longint;
	w : array[-300..300,-300..300] of longint;
begin
	fillchar(w,sizeof(w),0);
	readln(p,q);
	readln(n,r);
	for k := 1 to n do begin
		readln(a,b,v);
		for i := 0 to r do begin
			for j := 0 to r do begin
				inc(w[a-i+j,b+i-(r-j)],v);
			end;
		end;
		for i := 1 to r do begin
			for j := 0 to r-1 do begin
				inc(w[a-i+j+1,b+i-(r-j)],v);
			end;
		end;
	end;
	e := 0;
	for i := 1 to p do begin
		for j := 1 to q do begin
			if w[i,j] > e then begin
				e := w[i,j];
				x := i;
				y := j;
			end;
		end;
	end;
	writeln(x,' ',y, ' ', e);
end.
