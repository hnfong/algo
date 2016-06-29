program shell;
{
	shellsort code
}
const
	hc : array[1..10] of integer = ( 1023, 511, 255, 127, 63, 31, 15, 7, 3, 1 );
var
	i,j,k,t,n : longint;
	a : array[1..100000] of longint;
begin
	n := 0;
	while not eof do begin
		inc(n);
		readln(a[n]);
	end;
	
	for k := 1 to 10 do begin
		for i := 1+hc[k] to n do begin
			t := a[i];
			j := i - hc[k];
			while (j > 0) and (a[j] > t) do begin
				a[j+hc[k]] := a[j];
				j := j - hc[k];
			end;
			a[j+hc[k]] := t;
		end;
	end;
	

	for i := 1 to n do begin writeln(a[i]); end;
end.

