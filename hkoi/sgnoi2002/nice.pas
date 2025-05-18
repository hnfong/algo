program nice;
const
	hc : array [1..7] of integer = (
		2,7,6,5,4,3,2
	);

	hc2 : array[0..10] of char = (
		'J', 'A', 'B','C','D','E','F','G','H','I','Z'
	);
var
	i,j,k : longint;
	c : char;
	sum : longint;
begin
	assign(input, 'id.in');
	reset(input);
	assign(output, 'id.out');
	rewrite(output);
	sum := 0;
	for i := 1 to 7 do begin
		read(c);
		sum := sum + (ord(c)-48) * hc[i];
	end;
	writeln(hc2[sum mod 11]);
	close(input);
	close(output);
end.
