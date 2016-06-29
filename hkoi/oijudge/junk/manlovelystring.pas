program OI02JFQ2; {Lovely String }
var
  c , e : char;
  s : string;
  i : char;
  p : integer;

procedure r(a:char);
var
  i : char;
begin
  if a = c then
    writeln(s)
  else
  begin
    for i := chr(ord(s[p])+1) to c do
      if ((ord(s[p])-64)*5) <= ((ord(i)-64)*4) then
      begin
        s := s + i;
        p := p + 1;
        r(i);
        delete(s,p,1);
        p := p - 1;
      end;
  end;
end;

begin
  readln(c);
  e := chr(ord(c)-1);
  s := '';
  p := 0;
  for i := 'A' to e do
  begin
    s := s + i;
    p := p + 1;
    r(i);
    delete(s,p,1);
    p := p - 1;
  end;
end.

