program acm706;
{
@JUDGE_ID:  20044WC 706 PASCAL "Siliconism"
}
const	
	a : array[0..10,1..7] of byte = (
		(1, 1, 1, 0, 1, 1, 1),
		(0, 0, 1, 0, 0, 1, 0),
		(1, 0, 1, 1, 1, 0, 1),
		(1, 0, 1, 1, 0, 1, 1), 
		(0, 1, 1, 1, 0, 1, 0),
		(1, 1, 0, 1, 0, 1, 1),
		(1, 1, 0, 1, 1, 1, 1),
		(1, 0, 1, 0, 0, 1, 0),
		(1, 1, 1, 1, 1, 1, 1),
		(1, 1, 1, 1, 0, 1, 1),
		(1, 1, 1, 0, 1, 1, 1)
	);
var
	out : array[1..104, 1..23] of char;
	num : array[0..10] of byte;
	s : longint;
	c : char;
	n : longint;
	i,j,k : longint;
	t : string;

procedure dump;
var i,j,k : longint;
begin
	for i := 1 to s*2+3 do begin
		for j := 1 to (s+2+1)*n - 1 do begin
			write(out[j,i]);
		end;
		writeln;
	end;
	writeln;
end;

procedure gen(x, p: longint);
var
	offset : longint;
	i,j,k : longint;
begin
	offset := (p-1) * (s+2+1) + 1;
	if a[x, 1] > 0 then begin for i := offset + 1 to offset + s do begin out[i, 1] := '-'; end; end;
	if a[x, 2] > 0 then begin for j := 2 to 1+s do begin out[offset, j] := '|'; end; end;
	if a[x, 3] > 0 then begin for j := 2 to 1+s do begin out[offset+s+1, j] := '|'; end; end;
	if a[x, 4] > 0 then begin for i := offset + 1 to offset + s do begin out[i, 1+s+1] := '-'; end; end;
	if a[x, 5] > 0 then begin for j := 2+s+1 to 1+s+s+1 do begin out[offset, j] := '|'; end; end;
	if a[x, 6] > 0 then begin for j := 2+s+1 to 1+s+s+1 do begin out[offset+s+1, j] := '|'; end; end;
	if a[x, 7] > 0 then begin for i := offset + 1 to offset + s do begin out[i, 1+s+1+s+1] := '-'; end; end;
end;

begin
	while true do begin
		fillchar(out, sizeof(out), ' ');
		fillchar(num, sizeof(num), 0);
		read(s);
		if (s = 0) then break;
		n := 0;
		read(t);
		for i := 1 to length(t) do begin
			c := t[i];
			if (ord(c) < 48) or (ord(c) >= 58) then begin
				if (ord(c) = 10) or (ord(c) = 13) then break;
			end else begin
				inc(n);
				num[n] := ord(c) - 48;
			end;
		end;
		for i := 1 to n do begin gen(num[i], i); end;
		dump;
	end;
end.

