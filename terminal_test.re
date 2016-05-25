/*
   Translated from: https://github.com/diml/lambda-term/blob/master/examples/hello.ml
*/

open Lwt;
open Lwt_react;
open LTerm;
open LTerm_widget;

let main = fun () => {

    let ( waiter, wakener ) = wait ();

    let vbox = new LTerm_widget.vbox;
    vbox#add (new LTerm_widget.label "Hello world!");
    vbox#add (new LTerm_widget.label "Press Esc to exit.");

    let on_event = fun
        | LTerm_event.Key {LTerm_key.code: LTerm_key.Escape} => {
                wakeup wakener ();
                true
            }
        | _ => false;

    vbox#on_event on_event;

    let redraw = fun term => {
        
        LTerm_widget.run term vbox waiter
    };

    Lazy.force LTerm.stdout >>= redraw;
};

let () = Lwt_main.run (main ());

