# Part II: Approximate Solution Methods
* In part 1 the methods are applied to problems with arbitrarily large state spaces; impossible to find optimal value function/policy 
* Goal is to find a good approximate
* You need to generalize from experience - generalization is key

# Chapter 9: On-policy Prediction with Approximation

# David Silver Lecture 7: Policy Gradients
Model free learning

Value based RL:
* Epsilon greedy
* Learnt value function

Policy based:
* No value function 
* Learnt policy
* Advantages: better convergence, more effective in higher dimensional/continuous spaces, can learn stochastic policies
* Disadvantages: typically converges to local optimum, evaluating a policy is inefficient + high variance
* In the aliased gridworld example he shows how having a policy that randomly picks an action is better than a greedy policy that can't differentiate between states (identical states)

Actor-critic:
* Both VF and policy are learnt

## Policy Objective Functions
* Goal: given policy π(s, a) with parameters theta, find best theta
* To measure the quality of the policy, you can use:
    * Start state
    * Average value
    * Average reward per timestep
    * Stationary distribution of Markov chain for π_theta
* So this basically quantifies the return/how good a policy is. Like a value function, but not exactly? Check later.

## Policy Optimization
> Policy based RL is an optimization problem - find the parameters that maximize the return/value
|Non-Gradient|Gradient|
|-|-|
|Hill climbing|Gradient descent|
|Simplex/amoeba/Nelder Mead|Conjugate gradient|
|Genetic algorithms|Quasi-newton|

Gradient descent is cool, so we use that. And we use sequential structure to breakdown optimization to non-MC methods.

## Policy Gradient
> Karpathy's favorite
* Let J(theta) be any policy objective function
* Policy gradient algorithms search for a local maximum in J(theta) by ascending the gradient of the policy WRT parameters theta $$\delta\theta = \alpha\nabla_{\theta}J(\theta)$$




 
