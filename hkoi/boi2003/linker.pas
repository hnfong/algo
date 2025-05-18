program linker;
label hell1;
type
	s30 = string[30];
var
	i,j,n : longint;
	ex  : array[0..100] of longint;
	im	: array[0..100] of longint;
	w	: array[0..100,1..2,0..100] of longint; { 1 = export , 2 = import }
	v	: array[0..10000] of s30;
	u	: array[1..100] of boolean;
	r	: array[1..10000] of longint;
	q 	: longint;
	vsiz : longint;
	entryname : s30;
	entry : longint;
	nam : array[1..100] of s30;
	namsiz : longint;
	s : s30;
	z  : longint;

procedure dump;
var
	i : longint;
begin
	exit;
	writeln('******');
	writeln('start V');
	for i := 1 to vsiz do writeln(v[i]);
	writeln('end V');
	writeln('******');
end;
{function lookupname(s:s30):longint;
var	i : longint;
begin
	for i := 1 to namsiz do begin
		if namsiz
	end;
end;}

procedure registername(s:s30);
begin
	inc(namsiz);
	nam[namsiz] := s;
end;

function lookupsym(s:s30) : longint;
var i : longint;
begin
	for i := 1 to vsiz do begin
		if v[i] = s then begin
			lookupsym := i;
			exit;
		end;
	end;
	lookupsym := 0;
end;

function registersym(s:s30) : longint;
var	k :longint;
begin
	k := lookupsym(s);
	if k = 0 then begin
		inc(vsiz);
		v[vsiz] := s;
		k := vsiz;
	end;
	registersym := k;
end;

function common(x,y:longint):boolean;
var
	i,j : longint;
begin
	for i := 1 to im[x] do begin
		for j := 1 to ex[y] do begin
			if w[x,2,i] = w[y,1,j] then begin
				common := true;
				exit;
			end;
		end;
	end;
	common := false;
end;

procedure dfs(x: longint);
var
	i : longint;
begin
	if u[x] then exit;
	for i := 1 to ex[x] do begin
		inc( r[ w[x,1,i] ] );
	end;
	for i := 1 to im[x] do begin
		dec( r[ w[x,2,i] ] );
	end;
	u[x] := true;
	for i := 1 to n do begin
		if common(x,i) then dfs(i);
	end;
end;

begin
	assign(input,'LINKER.IN');
	reset(input);
	{assign(output,'LINKER.OUT');}
	rewrite(output);
	fillchar(w,sizeof(w),0);
	fillchar(v,sizeof(v),0);
	fillchar(nam,sizeof(nam),0);
	fillchar(u,sizeof(u),0);
	vsiz := 0; namsiz := 0;

	readln(entryname);
	readln(n);
	for i := 1 to n do begin
		readln(s);
		registername(s);
		readln(ex[i]);
		for j := 1 to ex[i] do begin
			readln(s);
			w[i,1,j] := registersym(s);
		end;
		readln(im[i]);
		for j := 1 to im[i] do begin
			readln(s);
			w[i,2,j] := registersym(s);
		end;
	end;
	dump;
	entry := lookupsym(entryname);
	for i := 1 to n do begin
		for j := 1 to ex[i] do begin
			if w[i,1,j] = entry then begin
				q := i;
				goto hell1;
			end;
		end;
	end;
	hell1:
	dec(r[entry]);
	dfs(q);
	z := 0;
	for i := 1 to n do begin if u[i] then inc(z); end;
	writeln(z);
	for i := 1 to n do begin
		if u[i] then writeln(nam[i]);
	end;
	z := 0;
	for i := 1 to vsiz do begin
		if r[i] > 0 then inc(z);
	end;
	writeln(z);
	for i := 1 to vsiz do begin
		if r[i] > 0 then writeln(v[i]);
	end;
	z := 0;
	for i := 1 to vsiz do begin
		if r[i] < 0 then inc(z);
	end;
	writeln(z);
	for i := 1 to vsiz do begin
		if r[i] < 0 then writeln(v[i]);
	end;
	close(input);
	close(output);
end.


