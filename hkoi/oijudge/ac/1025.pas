program p1025;
label hell;
var
	i,j,k,c,n,d,r : longint;
	u : array[0..9999] of longint;
	w : array[0..10000] of longint;
begin
	fillchar(w,sizeof(w),0);
	fillchar(u,sizeof(u),0);
	readln(n,d);
	write(n div d);
	k := n mod d;
	if k = 0 then goto hell;
	write('.');
	i := 0; r := -1;
	while u[0] = 0 do begin
		c := k*10 div d;
		k := k*10 mod d;
		if (u[k]>0) and (w[u[k]]=c) then begin
			r := u[k];
			break;
		end;
		inc(i);
		u[k] := i;
		w[i] := c;
	end;
	for j := 1 to i do begin
		if j=r then write('[');
		write(w[j]);
	end;
	if r >= 0 then write(']');
	hell:
	writeln;
end.
