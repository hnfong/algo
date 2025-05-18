program program3;
var
	i,j,k,l,m,n,t : longint;
	a : array[1..8000] of longint;
begin
	assign(input, 'input2.txt');
	reset(input);
	readln(n);
	for i := 1 to n do begin
		readln(a[i]);
	end;

	for i := 1 to n - 1 do
		for j := n - 1 downto i do begin
			if a[j] > a[j+1] then begin
				t := a[j];
				a[j] := a[j+1];
				a[j+1] := t;
			end;
		end;

	t := a[1] * (n-1);
	for i := 2 to n do begin
		t := t + a[i] * (n-i+1);
	end;

	writeln(t);
end.

