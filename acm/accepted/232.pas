program p232;
{
	@JUDGE_ID:  20044WC 232 PASCAL "DaP/DyP"
}
var
	i,j,k,n : longint;
	num : array[0..11,0..11] of longint;
	map : array[0..11,0..11] of char;
	r,c : longint;
	puzzlenumber : longint;
begin
	puzzlenumber := 0;

	while true do begin
		fillchar(num,sizeof(num), 255);
		fillchar(map,sizeof(map), 0);
		read(r);
		if r = 0 then break;
		if puzzlenumber > 0 then writeln;
		readln(c);
		for i := 1 to r do begin
			for j := 1 to c do begin
				read(map[i,j]);
				if map[i,j] <> '*' then num[i,j] := 0;
			end;
			readln;
		end;

		n := 0;
		{ assign numbers }
		for i := 1 to r do begin
			for j := 1 to c do begin
				if (num[i,j] = 0) and ((num[i-1,j] = -1) or (num[i,j-1] = -1)) then begin
					inc(n);
					num[i,j] := n;
				end;
			end;
		end;
		
		{ print mo liu stuff }
		inc(puzzlenumber);
		writeln('puzzle #', puzzlenumber, ':');
		
		{ across }
		writeln('Across');
		for i := 1 to r do begin
			for j := 1 to c do begin
				if (num[i,j] > 0) and (num[i, j-1] = -1) then begin
					write(num[i,j]:3, '.');
					for k := j to c do begin
						if num[i,k] = -1 then break;
						write(map[i,k]);
					end;writeln;
				end;
			end;
		end;
		
		{ across }
		writeln('Down');
		for i := 1 to r do begin
			for j := 1 to c do begin
				if (num[i,j] > 0) and (num[i-1, j] = -1) then begin
					write(num[i,j]:3, '.');
					for k := i to r do begin
						if num[k,j] = -1 then break;
						write(map[k,j]);
					end;writeln;
				end;
			end;
		end;
	end;
end.
