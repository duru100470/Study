const baseLink: string = `http://${document.location.hostname}:5000`;

function fetchGet(url: string) {
  return fetch(baseLink + url, {
    method: "GET",
    mode: "cors",
  });
}

function fetchPost(url: string, data: any) {
  console.log(`${url}\n${JSON.stringify(data)}`);
  return fetch(baseLink + url, {
    method: "POST",
    mode: "cors",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(data),
  });
}

function fetchPut(url: string, data: any) {
  return fetch(baseLink + url, {
    method: "PUT",
    mode: "cors",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(data),
  });
}

function fetchDelete(url: string) {
  return fetch(baseLink + url, {
    method: "DELETE",
    mode: "cors",
  });
}

export {
    fetchGet,
    fetchPost,
    fetchPut,
    fetchDelete
}