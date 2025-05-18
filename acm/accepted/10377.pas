program p10377;
{
	@JUDGE_ID:  20044WC 10377 PASCAL "Simulation"
}
const
	hc : array[0..3,1..2] of integer = (
		(0,-1),
		(1,0),
		(0,1),
		(-1,0)
	);
	hc2 : array[0..3] of char = ('N', 'E', 'S', 'W');
var
	d,x,y : longint;
	map : array[0..61,0..61] of char;
	testcases : longint;
	c : char;
	i,j,k : longint;
	m,n : longint;
	{col, row}
begin
	readln(testcases);
	readln;
	for k := 1 to testcases do begin
		fillchar(map,sizeof(map),'*');
		read(n,m);
		for i := 1 to n do begin
			for j := 1 to m do begin
				read(map[j,i]);
			end;readln;
		end;
		readln(y,x);
		d := 0;
		while not eof do begin {TODO}
			read(c);
			if (c = 'R') then begin
				d := (d+1) mod 4;
			end;
			if (c = 'L') then begin
				d := (d+4-1) mod 4;
			end;
			if (c = 'F') then begin
				if map[hc[d,1]+x, hc[d,2]+y] = ' ' then begin
					x := x + hc[d,1];
					y := y + hc[d,2];
				end;
			end;
			if (c = 'Q') then begin
				break;
			end;
		end;
		while not eoln do begin
		end; readln;
		writeln(y,' ',x,' ',hc2[d]);
		if k < testcases then writeln;
	end;
end.

