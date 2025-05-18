{
PROG: beads
ID: sydneyf1
}
program beads;
var
	i,j : longint;
	a : array[0..350] of char;
	n : longint;
	r,l : longint;
	f : longint;
function notrb(c:char):char;
begin
	if c = 'r' then notrb := 'b' else notrb:='r';
end;

begin
	assign(input,'beads.in');
	assign(output,'beads.out');
	reset(input);
	rewrite(output);
	f := 0;
	readln(n);
	for i := 1 to n do begin
		read(a[i]);
	end;
	for i := 1 to n do begin
		for j := 1 to n do begin
			a[j-1] := a[j];
		end;
		a[n] := a[0];
		
		r := 0;
		for j := 1 to n do begin
			if (a[j] = notrb(notrb(a[1]))) or (a[j] = 'w') then begin
				inc(r);
			end else begin
				break;
			end;
		end;
		 
		l := 0;
		for j := n downto 1 do begin
			if j = r then break;
			if (a[j] = notrb(a[1])) or (a[j] = 'w') then begin
				inc(l);
			end else begin
				break;
			end;
		end;
		if l+r > f then f := l+r;
	end;
	writeln(f);
	close(input);
	close(output);
end.
