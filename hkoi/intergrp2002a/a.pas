{ The dumb way of trying to solve the problem }
program intergroup2002a;
const hpas = 40 ; {the size of the array storing HPA data -> adjust accordingly}
const base = 10; {can be set to powers of 10 for faster computation }
type hpa = record
	l : longint;
	a : array[1..hpas] of longint;
end;
var
	a,b,c,d : hpa;
	gi : longint;

{ empties/initializes the hpa variable to all zeros }
{ note: might be unnecessary for some situations, because of hpa.l }
procedure inithpa(var x : hpa);
var i : longint; {l prefix = local var} begin x.l := 0; for i := 1 to hpas do begin x.a[i] := 0; end; end;

{ dumps the hpa variable to screen  with a deliminator of string dlim}
procedure dumphpa(var x : hpa; dlim : string);
var i : longint; begin for i := x.l downto 1 do begin write(x.a[i], dlim); end; writeln; end;

procedure dumpallhpa(var x : hpa; dlim : string);
var i : longint; begin for i := hpas downto 1 do begin write(x.a[i], dlim); end; writeln; end;

{ add two hpa data types and returns the result (still a hpa) }
function addhpa(var x, y : hpa) : hpa;
var
	c,i,j,k,m: longint; { m = max length of x or y }
	t  : hpa; {temporary}
begin
	c := 0;
	if (x.l > y.l) then m := x.l else m := y.l;
	for i := 1 to m+1 do begin {m+1 for last carry}
		t.a[i] := x.a[i] + y.a[i] + c;
		c := t.a[i] div base;
		t.a[i] := t.a[i] mod base;
	end;
	addhpa := t;
end;

function int2hpa(q : longint) : hpa;
var i : longint; t : hpa; {temp}

begin
	i := 0;
	inithpa(t);
	while q > 0 do begin
		i := i + 1;
		t.a[i] := q mod base;
		q := q div base;
	end;
	t.l := i;
	int2hpa := t;
end;
{ can be optimized }
procedure hpasqr2(var x : hpa; var y : hpa) ;
var i,j,k : longint; t,t2 : hpa;
	jmp : longint; {the number which jumps}
	c , c2 : longint ; {carry. carries when a character > 10, temporary}
	x1,x2 : longint;
	y1,y2 : longint;
begin
	if (x.l * 2 - 1) > hpas then begin
		writeln('ERROR: Exceeded data size!!! in HPASQR');
		exit;
	end;
	c := 0;
	c2 := 0;
	inithpa(t);
	inithpa(t2);
	y2 := -1;
	jmp := x.a[1] * x.a[1] mod base;
	for i := 1 to (x.l * 2 - 1) do begin
		x1 := c;
		y1 := c2;
		for j := 1 to i do begin
			if (j > x.l) or ((i-j+1) > x.l) then continue; {could be optimized to be in the for loop counter range rather than here}
			x1 := x1 + x.a[j] * x.a[i-j+1];
			y1 := y1 + y.a[j] * y.a[i-j+1];
		end;
		c := x1 div base;
		x1 := x1 mod base;
		c2 := y1 div base;
		y1 := y1 mod base;
		if (i > 1) and (i <= ((x.l*2-1) div 2) + (x.l*2-1) mod 2) then begin
			if x1 <> y2 then begin
				exit;
			end;
		end;
		if (i = (x.l*2-1) div 2 + (x.l*2-1) mod 2) then begin
			if y1 <> jmp then begin
				exit;
			end;
		end;
		if (i > (x.l*2-1) div 2 + (x.l*2-1) mod 2) then begin
			if x1 <> y1 then begin
{				dumphpa(a, '');}
{				write('last ! match');}
				exit;
			end;
		end;
		y2 := y1;
	end;
	writeln('MATCH:');
	dumphpa(x, '');
	t.l := x.l * 2 - 1;
end;

function ismatch (var x,y : hpa) : boolean;
var
	i,j,k : longint;
begin
	if x.l <> y.l then begin ismatch := false; exit; end;
	if x.a[1] <> y.a[(y.l div 2) + (y.l mod 2)] then begin ismatch := false; exit; end;
	for i := 1 to (x.l div 2) do begin
		if y.a[i] <> x.a[i+1] then begin ismatch := false; exit; end;
	end;
	for i := x.l downto (y.l div 2) + (y.l mod 2) + 1 do begin
		if y.a[i] <> x.a[i] then begin ismatch := false; exit; end;
	end;
	writeln('ISMATCHALL ', gi);
end;

begin
	for gi := 1000000000 to 2100000000 do begin
		if (gi mod 1000000) = 0 then begin
			writeln('last recorded : ', gi);
		end;
		write;
		if (gi mod 2) = 0 then begin
			a:=int2hpa(gi);
			hpasqr2(b,a);
		end else begin
			b:=int2hpa(gi);
			hpasqr2(a,b);
		end;
	end;
end.

