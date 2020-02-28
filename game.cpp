
     #include "TXLib.h"

     struct Shar
                {
                double x, y;
                double r;
                double vx, vy;
                COLORREF color;

                };



    void crug(Shar s);
    void ballMove ();
    double Distance (Shar s1, Shar s2);
    void Control1 (Shar* s1);
    void Control2 (Shar* s2);
    void Phisics (Shar* s);

    int main ()
        {

        txCreateWindow (800, 600);
        ballMove ();

        return 0;

        }

    void crug (Shar s)
        {

         txSetColor (s.color);
         txSetFillColor (s.color);
         txCircle (s.x, s.y, s.r);

        }

    void ballMove()
        {
         Shar s1{100, 100, 20, 10, 10, TX_RED};
         Shar s2{600, 200, 20, 10, 10, TX_BLUE};

        while(!txGetAsyncKeyState('M'))
            {
                txSetFillColor (TX_WHITE);
                txClear ();

                crug (s1);
                crug (s2);
                Phisics (&s1);
                Phisics (&s2);

                Control1 (&s1);
                Control2 (&s2);
                double dd=Distance (s1, s2);
                printf("%f    %f \n ", dd, s1.r + s2.r);
               if (dd <= s1.r + s2.r) break;

                txSleep(100);
            }
        }


         void Phisics(Shar* s)
            {

            s->x += s->vx;
            s->y += s->vy;

            if (s->x + s->r  >  800 && s->vx > 0) { s->vx = - s->vx; s->x = 800 - s->r ;}
            if (s->x - s->r  <    0 && s->vx < 0) { s->vx = - s->vx; s->x =   0 + s->r ;}
            if (s->y + s->r  >  600 && s->vy > 0) { s->vy = - s->vy; s->y = 600 - s->r ;}
            if (s->y - s->r  <    0 && s->vy < 0) { s->vy = - s->vy; s->y =   0 + s->r ;}

            }
        void Control1 (Shar* s1)
            {

            if (txGetAsyncKeyState (VK_LEFT))  s1->vx -= 3;
            if (txGetAsyncKeyState (VK_RIGHT)) s1->vx += 3;
            if (txGetAsyncKeyState (VK_UP))    s1->vx -= 3;
            if (txGetAsyncKeyState (VK_DOWN))  s1->vx += 3;

            }
        void Control2 (Shar* s2)
            {

            if (txGetAsyncKeyState ('A'))  (s2->vx)-=3;
            if (txGetAsyncKeyState ('R'))  (s2->vx)+=3;
            if (txGetAsyncKeyState ('w'))  (s2->vx)-=3;
            if (txGetAsyncKeyState ('s'))  (s2->vx)+=3;

            }
        double Distance (Shar s1, Shar s2)
            {

            double dist = sqrt ((s1.x - s2.x)*(s1.x - s2.x) + (s1.y - s2.y)*(s1.y - s2.y));
            return dist;

            }
