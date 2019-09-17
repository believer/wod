[@react.component]
let make = () => {
  let text = {j|
    # Glossary

    CrossFit contains a bunch of language that might seem confusing at first. Here are
      some terms which you'll often see pop up.

    ## WOD

    Workout of the Day

    ## RX

    Doing a workout _as prescribed_, meaning the same reps and weight as posted in the workout description.

    ## Scaled

    Scaling means adjusting the movement, weight or repetitions to
    accommodate your skill, abilities and strength. No one will think less of you for
    scaling a workout. Everyone does the workout depending on their current level.

    ## AMRAP

    **As Many Repetitions As Possible**, you are provided with a time frame in which you
    should try to achieve as many repetitions as possible.

    ## EMOM

    **Every Minute On The Minute**, at the start of every minute of a running clock
    you do some amount of work. It's common that the remainder of the minute is
    rest until the next minute starts.

    ## RFT

    **Rounds for Time**, complete X rounds as fast as possible.

    ## Time cap

    Maximum time allowed to perform the work.

    ## Chipper

    A linear workout, usually with a lot of exercises or reps, something you "chip
    away at". There are no rounds, simply start at the top and when you reach the
    end you're done.

    ## The Girls

    A special group of CrossFit benchmark workouts. When asked why name workouts after girls, CrossFit founder Greg Glassman responded:

    > "I thought that anything left you flat on your back looking up to the sky asking, 'what just happened,' deserved a female name."

    ## The Heroes

    CrossFit benchmark workouts created in honor of fallen soldiers or first
    responders, usually Americans. They are made to be performed with intense effort
    to honor the fallen Heroes. The most well-known hero workout is probably
    **Murph**.
    |j};

  <div className="my-20 grid grid-template-narrow">
    <div className="grid-column-main">
      <Markdown className="markdown" text />
    </div>
  </div>;
};
