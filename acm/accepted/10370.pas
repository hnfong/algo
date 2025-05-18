program avg;
{
@JUDGE_ID:  20044WC 10370 PASCAL "DaP/DyP"
}
var
	i,j,k : longint;
	r : double;
	n : longint;
	s,t : longint;
	a : array[1..1000] of longint;
	c : longint;
begin
	readln(n);
	for i := 1 to n do begin
		t := 0;
		c := 0;
		read(s);
		for j:= 1 to s do begin
			read(a[j]);
			t := t + a[j];
		end;
		readln;
		for j:= 1 to s do begin
			if (a[j] * s > t) then begin
				inc(c);
			end;
		end;
		writeln( ((c/s)*100):0:3 , '%' );
	end;
end.
