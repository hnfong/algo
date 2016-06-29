program p626;
var
	i,j,k : longint;
	v : array[1..1000,1..1000] of longint;
	n : longint;
	h,t : longint;
	w : array[1..1000] of boolean;
	a : array[1..3] of longint;
	lv : longint;
procedure order;
var i  : longint; t,k : longint;
begin
	for i := 0 to 2 do begin
		if (a[i mod 3 + 1] > a[(i+1) mod 3 + 1]) and (a[(i+1) mod 3 + 1] > a[(i+2) mod 3 + 1]) then begin
			t := i;
			break;
		end;
	end;
	for i := 0 to 2 do begin
		if (a[i mod 3 + 1] < a[(i+1) mod 3 + 1]) and (a[(i+1) mod 3 + 1] < a[(i+2) mod 3 + 1]) then begin
			t := i;
			break;
		end;
	end;
	for i := 1 to t do begin
		k := a[1];
		a[1] := a[2];
		a[2] := a[3];
		a[3] := k;
	end;
end;

procedure dfs(x:longint);
var i : longint; t : longint;
begin
	if lv >= 3 then begin
		if x = a[1] then begin
			order;
			for i := 1 to 3 do write(a[i], ' ');
			writeln;
		end;
		exit;
	end;
	if (lv <> 0) then if (v[a[lv],x] = 0) then exit;
	if w[x] = true then exit;
	 
	w[x] := true;
	inc(lv);
	a[lv] := x;
	for i := 1 to n do dfs(i);
	dec(lv);
	w[x] := false;
end;

begin
	while not eof do begin
		readln(n);
		if n > 1000 then while true do;
		for i := 1 to n do begin
			for j := 1 to n do begin
				read(v[i,j]);
			end;
			readln;
		end;
		for i := 1 to n do begin
			lv := 0;
			dfs(i);
		end;
		writeln('---');
	end;
end.
