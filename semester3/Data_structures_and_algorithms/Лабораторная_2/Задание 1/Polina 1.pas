program Polina1;

{$APPTYPE CONSOLE}

uses System;

type
    TPPolynomial = ^TPolynomial;
    TPolynomial = record
        n:    byte;
        a:    real;
        next: TPPolynomial;
    end;

var
    PtList1, PtList2, PtList3: TPPolynomial;
    x              : integer;
    flag           : boolean;
    
   
procedure Show(const Pt: TPPolynomial);
  var
    p: TPPolynomial;
  begin
    p := Pt;
    while p <> nil do
      begin
        write('(',p^.a,'*');
        write('x^',p^.n,')+');
        p := p^.next;
      end;  
  end;

//Процедура добавляет многочлены в список
procedure Pol_create(var PtList: TPPolynomial);   
  var
    Pt, Pt1: TPPolynomial;
    c      : byte;
    
  begin
    New(PtList);
    Pt := PtList;
     
    writeln('Polynomial: ');
    repeat
      New(Pt^.next);
      Pt1 := Pt;
      Pt := Pt^.next;
      write('Input n: '); read(Pt^.n);
      write('Input a: '); read(Pt^.a);
      writeln('Do you want to add 1 more element? Yes - 1, No - 0');
      if Pt^.a = 0 then
        begin
          dispose(pt);
          pt := pt1;
        end;
      readln(c);
    until c = 0;
    if Pt <> nil then
    Pt^.next := nil;
  end;

//Проверяет равенство многочленов p и q
function Equality(const p,q: TPPolynomial): boolean;
    var
      pt, pt1: TPPolynomial;
    begin
      equality := false;
      pt1 := p;
      while pt1 <> nil do
        begin
        pt := q;
          while pt <> nil do
            begin
              if (pt1^.a <> pt^.a) and (pt1^.n <> pt^.n) then
                begin
                  exit;  
                end;
              pt := pt^.next;
            end;
        pt1 := pt1^.next;
        end;
      equality := true;
    end;

//Вычисляет значение многочлена в целочисленной точке х
function Meaning(const p: TPPolynomial; const x: integer): integer;
    var
      S, x1: integer;
      P1   : TPPolynomial; 
    begin
      S  := 0;
      P1 := P;
      x1 := x;
      while P1 <> nil do
        begin
          x1 := round(P1^.a * (power(x,P1^.n)));
          S  := S + x1;
          P1 := P1^.next; 
        end;
      Meaning := S;
    end;

//Вычисляет сумму многочленов q и p, результат - многочлен r
procedure Add(const p,q: TPPolynomial; var r: TPPolynomial);
  var
    pt1, pt2, sum: TPPolynomial;
    flag         : boolean;
  begin
    pt1 := p;
    new(r);
    sum := r;
    
    while pt1 <> nil do
        begin
        pt2 := q;
          while pt2 <> nil do
            begin
              if pt1^.n = pt2^.n then
                begin
                  new(sum^.next);
                  sum := sum^.next;
                  sum^.a := pt1^.a + pt2^.a;
                  sum^.n := pt1^.n;
                end
              else
                begin
                  new(sum^.next);
                  sum := sum^.next;
                  sum^.a := pt1^.a;
                  sum^.n := pt1^.n;
                end;
              pt2 := pt2^.next;
            end;
        pt1 := pt1^.next;
        end; 
        
     pt2 := q;
     while pt2 <> nil do
        begin
        flag := true;
        pt1 := p;
          while pt1 <> nil do
            begin
              if pt2^.n = pt1^.n then
                begin
                  flag := false;  
                end;
              pt1 := pt1^.next;
            end;
           
           if flag then
             begin
              new(sum^.next);
              sum := sum^.next;
              sum^.a := pt2^.a;
              sum^.n := pt2^.n;
             end;
        pt2 := pt2^.next;
        end;
        sum^.next := nil;
  end;



begin
    Pol_create(PtList1);
    Pol_create(PtList2);
    
    PtList1 := PtList1^.next;
    PtList2 := PtList2^.next;
    writeln('Введите х: '); readln(x);
    x := Meaning(PtList1,x);
      
    writeln('Значение многочлена = ',x);
    
    flag := false;
    flag := equality(PtList1,Ptlist2);
    if flag then
      writeln('Многочлены  равны')
    else
      writeln('Многочлены не равны');
    
    Add(PtList1,PtList2,PtList3);
    write('P1 = ');
    Show(PtList1);
    writeln;
    write('P2 = ');
    Show(PtList2);
    writeln;
    PtList3 := PtList3^.next;
    write('P3 = ');
    Show(PtList3);

    readln;
end.