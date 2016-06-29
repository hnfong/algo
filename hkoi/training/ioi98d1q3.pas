program CelebiX;
const	maxn = 10;
	hard : array [1..8,1..6] of byte = (
	 (0,0,0,0,0,0),
	 (0,1,0,1,0,1),
	 (1,0,1,0,1,0),
	 (0,1,1,0,1,1),
	 (1,1,0,0,0,1),
	 (0,0,1,1,1,0),
	 (1,0,0,1,0,0),
	 (1,1,1,1,1,1)
	);
var
	f : array[1..100] of shortint;
	dq : array[1..8] of shortint;
	c,i,j,k,n,t : longint;
procedure dump;
begin
	for i := 1 to maxn do begin
		write(f[i]:3);
	end;
	writeln;
end;

begin
	assign(input, 'party.in');
	reset(input);
	assign(output, 'party.out');
	rewrite(output);
	fillchar(dq, sizeof(dq), 0);
	fillchar(f, sizeof(f), 255);
	readln(n);
	readln(c);
	while true do begin
		read(t);
		if t = -1 then break;
		f[t] := 1;
	end;

	while true do begin
		read(t);
		if t = -1 then break;
		f[t] := 0;
	end;
	if (c = 1) then begin
		for i := 5 to 8 do dq[i] := 1;
	end;
	if (c = 2) then begin
		dq[4] := 1;
	end;
	for i := 1 to n do begin
		if f[i] >= 0 then begin
			for j := 1 to 8 do begin
				if dq[j] > 0 then continue;
				if hard[j,((i-1) mod 6)+1] <> f[i] then begin
					dq[j] := 1;
				end;
			end;
		end;
	end;
	for i := 1 to 8 do begin
		if dq[i] = 0 then begin
			for j := 1 to n do begin
				write(hard[i, ((j-1) mod 6) + 1]);
			end;
			writeln;
		end;
	end;
	close(output);
end.

