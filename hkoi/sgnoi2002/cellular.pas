program celluar;
var
	code : array[0..5] of byte;
	i,j,k,l : longint;
	a : array[0..3,0..31,0..31] of byte;
	cur : longint;
	nex : longint;
	n,g : longint;
	sum : longint;
	c : char;
procedure dump;
begin	
	exit;
	for i := 0 to 5 do begin
		write(code[i]);
	end;
	writeln;
	for i := 0 to n+1 do begin
		for j:=0 to n+1 do begin
			write(a[cur, i,j ]);
		end;
		writeln;
	end;
	writeln;
end;
function same : boolean;
var
	i,j,k : longint;
begin
	for i := 1 to n do begin
		for j  := 1 to n do begin
			if a[nex,i,j] <> a[3,i,j] then begin
				same := false;
				exit;
			end;
		end;
	end;
	same := true;
	exit;
end;
procedure add;
var i : longint;
begin
	inc(code[0]);
	for i := 0 to 4 do begin
		if code[i] > 1 then begin code[i] := 0; inc(code[i+1]); end;
	end;
end;
begin
	g := 0;
	cur := 0;
	fillchar(a, sizeof(a), 0);
	fillchar(code, sizeof(code), 0);
	assign(input, 'cellular.in');
	reset(input);
	assign(output, 'cellular.out');
	rewrite(output);
	read(n);
	readln(g);
	for i := 1 to n do begin
		for j := 1 to n do begin
			read(c);
			a[2, i,j] := ord(c) - 48;
		end;
		readln;
	end;
	readln;
	for i := 1 to n do begin
		for j := 1 to n do begin
			read(c);
			a[3, i,j] := ord(c) - 48;
		end;
		readln;
	end;
	
	for l := 0 to 63 do begin
		a[0] := a[2];
		for k := 0 to g-1 do begin
			cur := k mod 2;
			nex := (cur + 1) mod 2;
			for i := 1 to n do begin
				for j := 1 to n do begin
					sum := a[cur,i,j-1]+a[cur,i+1,j]+a[cur,i,j+1]+a[cur,i-1,j]+a[cur,i,j];
					a[nex,i,j] := code[sum];
				end;
			end;
		end;
		if same then begin writeln(l); close(output); exit; end;
		add;
	end;
end.

