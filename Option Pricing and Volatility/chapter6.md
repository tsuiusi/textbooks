# Chapter 6: Option Values and Changing Market Conditions
> Don't lose money - "a trader who fails to consider thew risks associated with his position is certain to have a short an unhappy career"

### General effects of market changes
|If...|Call values will...|Put values will...|
|Price of UC increases|rise|fall|
|Price of UC decreases|fall|rise|
||||||
|Volatility rises|rise|rise|
|Volatility falls|falls|falls|
||||||
|Time passes|fall|fall|
(usually)
* Interest rates cannot be generalized, but we can look at the effect on an UC
    * High -> call, since we can appreciate via interest rates
    * Low -> UC, since carrying cost is not as great
* Opposite for puts
* In foreign currencies, buy whichever one has a higher interest rate
* Stock and foreign currency are always assumed to have stock-type settlement

### More generalizations
| Interest | If Domestic Interest Rates Rise | If Domestic Interest Rates Fall | If Foreign Interest Rates Rise | If Foreign Interest Rates Fall |
|----------|--------------------------------|--------------------------------|-------------------------------|-------------------------------|
| Calls on stock will | rise in value | fall in value | (not applicable) | (not applicable) |
| Puts on stock will | fall in value | rise in value | (not applicable) | (not applicable) |
| Calls on a foreign currency will | rise in value | fall in value | fall in value | rise in value |
| Puts on a foreign currency will | fall in value | rise in value | rise in value | fall in value |
| Calls on a futures contract will (stock type settlement) | rise in value | fall in value | (not applicable) | (not applicable) |
| Puts on a futures contract will (stock type settlement) | fall in value | rise in value | (not applicable) | (not applicable) |
| Calls on a futures contract will (futures type settlement) | remain unchanged | remain unchanged | (not applicable) | (not applicable) |
| Puts on a futures contract will (futures type settlement) | remain unchanged | remain unchanged | (not applicable) | (not applicable) |

Dividends
| If... | Call values will... | Put values will... |
|-------|---------------------|---------------------|
| The dividend is increased | fall | rise |
| The dividend is decreased | rise | fall |

## The Delta 
Again, it's the partial derivative of the predicted option price WRT the UC price.
* Always between 0 to 100%

### Rate of change
> Delta can be interpreted as the **rate of change**
* Interpret it as the rate of change relative to the UC (75 = 75% rate of change)
* Puts have similar characteristics, except the values move in opposite directions
    * UC increases -> puts lose value
    * Puts always have negative deltas

### Hedge ratio
* The ratio of underlying contracts to options required to stay delta-neutral
* 100 / delta

### Theoretical/Equivalent underlying position
* Each 100 deltas represents a theoretical position equivalent to one underlying contract
    * So if the delta of an option owned is 50 then you're long 1/2 an UC
    * Vice versa, owning 100 UCs mean you're long 200 options
* Winning small 19 times might be less than winning once but it's insanely big

## The Gamma
> Rate of change of delta WRT UC price
* Greatest when an option is at-the-money 
* Delta neutral position depends on an estimate of current market conditions
* As he changes his assumptions, he must constantly change his trading strategies to fit these new assumptions
(see page 118 in the pdf for more diagrams)

## The Theta
> Time decay factor - the rate of option value loss 
* E.g option with $\theta = 0.05$ will lose 0.05 dollars of value each day with no other change in market conditions (2.75 -> 2.70)
* **Long options always negative theta; short options always positive**
* When the carrying cost is greater than the volatility component, the option is European and have a theoretical value of less than parity and rise as it slowly approaches expirty date
* Most options just lose value as time passes

## The Vega/Kappa (means the same thing)
> Rate of change of theoretical value WRT change in volatility
* Point change in theoretical value per percentage point change in volatility

Characteristics:
* Always positive for both calls and puts
* Highest for at-the-money options
* Increases with time to expiration

## The Rho
> Sensitivity of an option's theoretical value WRT interest rates
* Sensitivity to foreign interest rates are sometimes denoted with phi $\phi$
* When options are subject to futures-type settlement, rho is 0 since interest doesn't matter
* When the options are subject to stock-type settlement, rho is always negative for calls and puts
    * Increasing interest rates increase carrying costs

* Generally disregarded
