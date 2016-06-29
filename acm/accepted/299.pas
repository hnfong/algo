program p299;
{
@JUDGE_ID:  20044WC 299 PASCAL "High School Bubble"
}
var
	i,j,k : longint;
	a : array [1..1000] of longint;
	n : longint;
	f : longint;
	x,y : longint;

begin
	readln(x);
	for y := 1 to x do begin
		readln(n);
		for i := 1 to n do begin
			read(a[i]);
		end;
		readln;
		inc(f);
		f := 0;
		for i := 1 to n do begin
			for j := i downto 2 do begin
				if a[j] < a[j-1] then begin
					k := a[j];
					a[j] := a[j-1];
					a[j-1] := k;
					inc(f);
				end;
			end;
		end;
		writeln('Optimal train swapping takes ', f, ' swaps.');
	end;
end.

