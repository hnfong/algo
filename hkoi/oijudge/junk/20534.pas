program p20534;
var
	i,j,k,n : longint;
	w : array[1..200,1..200] of double;
	x,y : array[1..200] of longint;
function max (x,y:double):double;
begin
	if x < y then max := y else max := x;
end;
begin
	readln(n);
	for i := 1 to n do begin
		readln(x[i],y[i]);
		for j := 1 to i - 1 do begin
			w[i,j] := sqrt( sqr(x[i]-x[j])+sqr(y[i]-y[j]) );
			w[j,i] := sqrt( sqr(x[i]-x[j])+sqr(y[i]-y[j]) );
		end;
	end;
	for k := 1 to n do begin
		for i := 1 to n do begin
			for j := 1 to n do begin
				if max(w[i,k],w[k,j]) < w[i,j] then begin
					w[i,j] := max(w[i,k],w[k,j]);
				end;
			end;
		end;
	end;
	writeln(w[1,2]:0:3);
end.

