program p101;
{
@JUDGE_ID:  20044WC 101 PASCAL "DaP/DyP"
}
var
	a : array [0..100,0..100] of longint;
	p : array [0..100, 0..2] of longint;
	i,j,k : longint;
	n  : longint;
	c1,c2  : string[5];
	f, t : longint;
procedure dump;var i,j : longint;
begin
	for i := 0 to n-1 do begin
		write(i,':');
		for j := 1 to a[i,0] do begin
			write(' ', a[i,j]);
		end;
		writeln;
	end;
end;
procedure mv(x,d:longint);
begin
	if x < 0 then exit; if d < 0 then exit; if x >= n then exit; if d >= n then exit;
	if p[x,1] = d then exit;
	dec(a[p[x,1], 0]);
	a[p[x,1],p[x,2]] := 0;
	inc(a[d,0]);
	a[d,a[d,0]] := x;
	p[x,1] := d;
	p[x,2] := a[d,0];
end;

procedure ret(x:longint);
var i : longint;
begin
	if x < 0 then exit; if x >= n then exit;
	for i := a[p[x,1], 0] downto p[x,2]+1 do begin
		mv(a[p[x,1],i], a[p[x,1],i]);
	end;
end;

procedure pile(x,d : longint);
var i,tr,tc,tz : longint;
begin
	if x < 0 then exit; if d < 0 then exit; if x >= n then exit; if d >= n then exit;
	if p[x,1] = d then exit;
	tr := p[x,1];
	tc := p[x,2];
	tz := a[tr, 0];
	for i := tc to tz  do begin
		mv(a[tr,i], d);
	end;
end;

begin
	fillchar(a, sizeof(a), 0);
	readln(n);
	for i := 0 to n-1 do begin
		a[i,0] := 1;
		a[i,1] := i;
		p[i,2] := 1;
		p[i,1] := i;
	end;
	while not eof do begin
		read(c1);
		if c1 = 'quit' then break;
		readln(f,c2,t);
		if f = t then continue;
		if p[f,1] = p[t,1] then continue;
		if pos('mo',c1) > 0 then begin
			if pos('on', c2) > 0 then begin
				ret(f);
				ret(t);
				mv(f,p[t,1]);
			end;

			if pos('ov', c2) > 0 then begin
				ret(f);
				mv(f,p[t,1]);
			end;
		end;
		if pos('pi',c1) > 0 then begin
			if pos('on', c2) > 0 then begin
				ret(t);
				pile(f,p[t,1]);
			end;
			if pos('ov', c2) > 0 then begin
				pile(f,p[t,1]);
			end;
		end;
	end;
	dump;
end.

