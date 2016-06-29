program b;
{
	Generates 3x3 magic squares
}
var
	i,j,k : longint;
	a : array[1..9] of byte;
	u : array[1..9] of boolean;
	c : longint;

function check : boolean;
var t : longint; i,j : longint;
begin
	t := (a[1] + a[2] + a[3]);
	if t <> (a[4] + a[5] + a[6]) then exit;
	if t <> (a[7] + a[8] + a[9]) then exit;
	if t <> (a[1] + a[4] + a[7]) then exit;
	if t <> (a[2] + a[5] + a[8]) then exit;
	if t <> (a[3] + a[6] + a[9]) then exit;
	if t <> (a[1] + a[5] + a[9]) then exit;
	if t <> (a[3] + a[5] + a[7]) then exit;
	for i := 0 to 2 do begin
		for j := 1 to 3 do begin
			write(a[j+i*3]);
		end;writeln;
	end;writeln;
end;

procedure gen(x : longint);
var i : longint;
begin
	if c = 9 then exit;
	if u[x] then exit;
	u[x] := true;
	inc(c);
	a[c] := x;
	if c = 9 then begin
		check;
	end;
	for i := 1 to 9 do begin
		gen(i);
	end;
	dec(c);
	u[x] := false;
end;

begin
	c := 0;
	for i := 1 to 9 do gen(i);
end.
