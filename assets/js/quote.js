function getQuote() {
  let randomQuote = beerq.BeerQuote("eng").getRandomQuote();
  document.getElementById("quote").innerHTML = "<br><i>" + randomQuote.quote + "<br>[" + randomQuote.author + "]</i>";
}

setInterval(getQuote, 10000); /*Call it here*/
getQuote();