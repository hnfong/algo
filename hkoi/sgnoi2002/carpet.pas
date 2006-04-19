program carpet;
var
	i,j,k,l : longint;
	a : array[1..40,1..40] of char;
	b : array[1..40,1..40] of longint;
	r, c : longint;
	n : longint;
	x , y : longint;
	m : longint;
	cmin : longint;
procedure dump;
var i,j : longint;
begin
	for i := 1 to r do begin
		for j := 1 to c do begin
			write(a[i,j]);
		end;
		writeln;
	end;
	for i := 1 to r do begin
		for j := 1 to c do begin
			write(b[i,j], ' ');
		end;
		writeln;
	end;
end;

begin
	fillchar(a, sizeof(a), '.');
	fillchar(b, sizeof(b), 0);
	assign(input, 'carpet.in');
	reset(input);
	read(r);
	readln(c);
	readln(n);
	for i := 1 to n do begin
		read(x);
		readln(y);
		a[x,y] := '#'
	end;
	for i := 1 to r do begin
		for j := 1 to c do begin
			if a[i,j] = '#' then continue;
			cmin := 100;
			for k := i to r do begin
				for l := j to c+1 do begin
					if (l>c) or (a[k,l] = '#') or (l >= cmin) then begin
						if b[i,j] < ((k-i+1) * (l-j)) then b[i,j] := (k-i+1) * (l-j);
						cmin := l;
						break;
					end;
				end;
			end;
		end;
	end;
	dump;
	m := 0;
	for i := 1 to r do begin
		for j := 1 to c do begin
			if m < b[i,j] then m := b[i,j];
		end;
	end;
	assign(output, 'carpet.out');
	rewrite(output);
	writeln(m);
	close(output);
end.
