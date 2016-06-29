program p534;
{
	@JUDGE_ID: 20044WC 534 PASCAL "DaP/DyP"
}
var
	i,j,k : longint;
	w : array[1..200,1..200] of single;
	x,y : array[1..200] of integer;
	t1,t2 : longint;
	n : longint;
	ni : longint;
function maxs(x,y:single):single;
begin
	if x > y then maxs := x else maxs := y;
end;

begin
	ni := 0;
	while not eof do begin
		readln(n);
		if n = 0 then break;
		inc(ni);

		{ read input }
		for i := 1 to n do begin
			readln(x[i],y[i]);
		end;readln;

		{ construct graph }
		for i := 1 to n do begin
			for j := i+1 to n do begin
				{ Pythegoras Theorem! }
				t1 := x[i]-x[j];
				t2 := y[i]-y[j];
				w[i,j] := sqrt(t1*t1+t2*t2);
				w[j,i] := w[i,j];
			end;
		end;
	
		{ warshall }
		for k := 1 to n do
		for i := 1 to n do
		for j := 1 to n do
		if (w[i,k] < w[i,j]) and (w[k,j] < w[i,j]) then
		w[i,j] := maxs(w[k,j],w[i,k]);
		{ floyd }

		writeln('Scenario #',ni);
		writeln('Frog Distance = ', w[1,2]:0:3);
		writeln;
	end;
end.
