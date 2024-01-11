import { BeerQuote } from "./beerq";

function getQuote() {
  let randomQuote = BeerQuote.getRandomQuote();
  document.getElementById("quote").innerHTML = "<i>" + randomQuote.quote + "</i>";
  document.getElementById("author").innerHTML = randomQuote.author;
}

setInterval(getQuote, 5000); /*Call it here*/
getQuote();