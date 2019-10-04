module Auth0 = {
  let domain = [%bs.raw "process.env.AUTH_DOMAIN"];
  let client = [%bs.raw "process.env.AUTH_CLIENT"];
  let redirect = [%bs.raw "process.env.AUTH_REDIRECT"];
};
